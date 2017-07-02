#include "zappy_ai_stdafx.hpp"

namespace ai
{
  static const std::map<
      State, std::array<State, static_cast<std::int32_t>(Value::NB_VALUE)>>
      transitionTable = {
          {State::STARVING,
           {{State::FOOD_ON_CASE, State::RECEIVE_MSG, State::NO_CHANGE,
             State::NO_CHANGE, State::MISSING_STONE, State::MISSING_PLAYER,
             State::RECEIVE_MSG, State::NO_CHANGE}}},
          {State::RECEIVE_MSG,
           {{State::NO_CHANGE, State::MISSING_STONE, State::LEVEL,
             State::MISSING_STONE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::MISSING_STONE}}},
          {State::MISSING_STONE,
           {{State::STONE_ON_CASE, State::MISSING_PLAYER, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::MISSING_PLAYER,
           {{State::NO_CHANGE, State::SET_RECIPE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::SET_RECIPE,
           {{State::INCANT, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::INCANT,
           {{State::STARVING, State::MISSING_STONE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::FOOD_ON_CASE,
           {{State::COLLECT_FOOD, State::FIND_FOOD, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::COLLECT_FOOD,
           {{State::STARVING, State::FOOD_ON_CASE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::FIND_FOOD,
           {{State::MOVE_TO_FOOD, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::MOVE_TO_FOOD,
           {{State::FOOD_ON_CASE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::LEVEL,
           {{State::MOVE_TO_TEAMMATE, State::MISSING_STONE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::MOVE_TO_TEAMMATE,
           {{State::ARRIVED, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::ARRIVED,
           {{State::FIX_RECIPE, State::STARVING, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::STARVING, State::NO_CHANGE}}},
          {State::FIX_RECIPE,
           {{State::ARRIVED, State::ARRIVED, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::STONE_ON_CASE,
           {{State::COLLECT_STONE, State::FIND_STONE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::COLLECT_STONE,
           {{State::STARVING, State::STONE_ON_CASE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::FIND_STONE,
           {{State::MOVE_TO_STONE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::STARVING, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::MOVE_TO_STONE,
           {{State::STONE_ON_CASE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::STARVING, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::TROLL,
           {{State::MISSING_STONE, State::MISSING_STONE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
          {State::INIT_AI,
           {{State::STARVING, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE, State::NO_CHANGE,
             State::NO_CHANGE, State::NO_CHANGE}}},
  };

  AI::AI(std::string const &ip, std::uint16_t port, std::string const &teamname)
      : m_states(), m_curState(State::STARVING), m_curValue(Value::YES),
        m_network(ip, port), m_player(m_network), m_alive(true)
  {
    if (m_network.receive() != "WELCOME")
      {
	throw std::runtime_error("Failed to communicate with the server");
      }

    m_network.send(teamname);

    nope::log::Log(Debug) << "Client slot remaining for team " << teamname
                          << ": " << m_network.receive();
    nope::log::Log(Debug) << "Map size: " << m_network.receive();

    initState();
  }

  AI::~AI()
  {
  }

  void AI::loop()
  {
    State oldState;

    while (m_alive)
      {
	oldState = m_curState;
	m_curValue = (this->*m_states[static_cast<std::size_t>(m_curState)])(
	    m_curValue);

	m_curState = transitionTable.at(m_curState)[m_curValue];
	if (m_curState == State::NO_CHANGE)
	  {
	    m_curState = oldState;
	  }
      }
  }

  void AI::initState()
  {
    // m_states[State::DEAD] = &AI::;
    m_states[State::STARVING] = &AI::starving;
    m_states[State::RECEIVE_MSG] = &AI::receiveMessage;
    m_states[State::MISSING_STONE] = &AI::missingStone;
    m_states[State::MISSING_PLAYER] = &AI::missingPlayer;
    m_states[State::SET_RECIPE] = &AI::setRecipe;
    m_states[State::INCANT] = &AI::incant;
    m_states[State::FOOD_ON_CASE] = &AI::foodOnCase;
    m_states[State::COLLECT_FOOD] = &AI::collectFood;
    m_states[State::FIND_FOOD] = &AI::findFood;
    m_states[State::MOVE_TO_FOOD] = &AI::moveToFood;
    m_states[State::LEVEL] = &AI::level;
    m_states[State::MOVE_TO_TEAMMATE] = &AI::moveToTeammate;
    m_states[State::ARRIVED] = &AI::arrived;
    m_states[State::FIX_RECIPE] = &AI::fixRecipe;
    m_states[State::STONE_ON_CASE] = &AI::stoneOnCase;
    m_states[State::COLLECT_STONE] = &AI::collectStone;
    m_states[State::FIND_STONE] = &AI::findStone;
    m_states[State::MOVE_TO_STONE] = &AI::moveToStone;
    m_states[State::TROLL] = &AI::troll;
  }

  Value AI::starving(Value)
  {
    if (m_player.updateInventory())
      {
	int food = m_player.get("food");

	if (food < NB_FOOD_NORMAL)
	  {
	    return (Value::YES);
	  }
	else
	  {
	    return (Value::NO);
	  }
      }
    return (Value::NO);
  }

  Value AI::receiveMessage(Value)
  {
    return (Value::NO);
  }

  Value AI::missingStone(Value)
  {
    return (Value::NO);
  }

  Value AI::missingPlayer(Value)
  {
    return (Value::NO);
  }

  Value AI::setRecipe(Value)
  {
    return (Value::NO);
  }

  Value AI::incant(Value)
  {
    return (Value::NO);
  }

  Value AI::foodOnCase(Value)
  {
    if (m_player.updateLook())
      {
	if (m_player.find("food") == 0)
	  {
	    return (Value::YES);
	  }
	else
	  {
	    return (Value::NO);
	  }
      }
    return (Value::NO);
  }

  Value AI::collectFood(Value)
  {
    if (m_player.take("food"))
      {
	return (Value::YES);
      }
    return (Value::NO);
  }

  Value AI::findFood(Value)
  {
    if (m_player.updateLook())
      {
	std::int32_t food = m_player.find("food");

	if (food == -1)
	  {
	    m_player.right();
	    return (Value::NO);
	  }
	else
	  {
	    m_player.setFoodTarget(food);
	    return (Value::YES);
	  }
      }
    return (Value::NO);
  }

  Value AI::moveToFood(Value)
  {
    std::pair<std::int32_t, std::int32_t> dir =
        m_player.getDirection(m_player.getFoodTarget());

    if (m_player.moveTo(dir.first, dir.second))
      {
	return (Value::YES);
      }

    return (Value::NO);
  }

  Value AI::level(Value)
  {
    return (Value::NO);
  }

  Value AI::moveToTeammate(Value)
  {
    return (Value::NO);
  }

  Value AI::arrived(Value)
  {
    return (Value::NO);
  }

  Value AI::fixRecipe(Value)
  {
    return (Value::NO);
  }

  Value AI::stoneOnCase(Value)
  {
    return (Value::NO);
  }

  Value AI::collectStone(Value)
  {
    return (Value::NO);
  }

  Value AI::findStone(Value)
  {
    return (Value::NO);
  }

  Value AI::moveToStone(Value)
  {
    return (Value::NO);
  }

  Value AI::troll(Value)
  {
    return (Value::NO);
  }

  Value AI::initAI(Value)
  {
    return (Value::NO);
  }
}
