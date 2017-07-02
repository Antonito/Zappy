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

  AI::AI(std::string const &ip, std::uint16_t port,
         std::string const &teamname)
      : m_states(), m_curState(State::STARVING), m_curValue(Value::YES),
        m_network(ip, port), m_player(m_network), m_alive(true), m_loop(0)
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
    nope::log::Log(Debug) << "STATE : Starving";
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
    nope::log::Log(Debug) << "STATE : ReceiveMessage";
    return (Value::NO);
  }

  Value AI::missingStone(Value)
  {
    nope::log::Log(Debug) << "STATE : MissingStone";
    //     if (m_player.updateInventory())
    //       {
    // 	std::array<std::int32_t, 6> stoneTab =
    // 	    m_player.missingStone(m_player.getInventory());
    // 	for (std::int32_t i = 0; i < 6; ++i)
    // 	  {
    // 	    if (stoneTab[static_cast<std::size_t>(i)] > 0)
    // 	      {
    // 		m_player.setStoneName(m_player.getNameForIdStone(i));
    // 		return (Value::YES);
    // 	      }
    // 	  }
    //       }
    return (Value::NO);
  }

  Value AI::missingPlayer(Value)
  {
    nope::log::Log(Debug) << "STATE : MissingPlayer";
    return (Value::NO);
  }

  Value AI::setRecipe(Value)
  {
    nope::log::Log(Debug) << "STATE : SetRecipe";
    return (Value::NO);
  }

  Value AI::incant(Value)
  {
    nope::log::Log(Debug) << "STATE : Incant";
    if (m_player.incant())
      {
	// TODO: wait for second OK
	return (Value::YES);
      }
    return (Value::NO);
  }

  Value AI::foodOnCase(Value)
  {
    nope::log::Log(Debug) << "STATE : FoodOnCase";
    if (m_player.updateLook())
      {
	std::int32_t find = m_player.find("food");

	nope::log::Log(Debug) << "Found food on " << find;
	if (find == 0)
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
    nope::log::Log(Debug) << "STATE : CollectFood";
    if (m_player.take("food"))
      {
	return (Value::YES);
      }
    return (Value::NO);
  }

  Value AI::findFood(Value)
  {
    nope::log::Log(Debug) << "STATE : FindFood";
    if (m_player.updateLook())
      {
	std::int32_t food = m_player.find("food");

	if (food == -1)
	  {
	    if (m_loop < 4)
	      {
		m_player.right();
		++m_loop;
	      }
	    else
	      {
		m_player.forward();
		m_loop = 0;
	      }
	    return (Value::NO);
	  }
	else
	  {
	    m_player.setFoodTarget(food);
	    m_loop = 0;
	    return (Value::YES);
	  }
      }
    return (Value::NO);
  }

  Value AI::moveToFood(Value)
  {
    nope::log::Log(Debug) << "STATE : MoveToFood";
    std::pair<std::int32_t, std::int32_t> dir =
        m_player.getDirection(m_player.getFoodTarget());

    if (m_player.moveTo(dir.first, dir.second))
      {
	m_player.setFoodTarget(0);
	return (Value::YES);
      }
    return (Value::NO);
  }

  Value AI::level(Value)
  {
    nope::log::Log(Debug) << "STATE : Level";
    return (Value::NO);
  }

  Value AI::moveToTeammate(Value)
  {
    nope::log::Log(Debug) << "STATE : MoveToTeammate";
    return (Value::NO);
  }

  Value AI::arrived(Value)
  {
    nope::log::Log(Debug) << "STATE : Arrived";
    return (Value::NO);
  }

  Value AI::fixRecipe(Value)
  {
    nope::log::Log(Debug) << "STATE : fixRecipe";
    return (Value::NO);
  }

  Value AI::stoneOnCase(Value)
  {
    nope::log::Log(Debug) << "STATE : stoneOnCase";
    if (m_player.updateLook())
      {
	if (m_player.find(m_player.getStoneName()) == 0)
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

  Value AI::collectStone(Value)
  {
    nope::log::Log(Debug) << "STATE : CollectStone";
    if (m_player.take(m_player.getStoneName()))
      {
	return (Value::YES);
      }
    return (Value::NO);
  }

  Value AI::findStone(Value)
  {
    nope::log::Log(Debug) << "STATE : FindStone";
    if (m_player.updateLook())
      {
	std::int32_t stone = m_player.find(m_player.getStoneName());

	if (stone == -1)
	  {
	    m_player.right();
	    return (Value::NO);
	  }
	else
	  {
	    m_player.setStoneTarget(stone);
	    return (Value::YES);
	  }
      }
    return (Value::NO);
  }

  Value AI::moveToStone(Value)
  {
    nope::log::Log(Debug) << "STATE : moveToStone";
    std::pair<std::int32_t, std::int32_t> dir =
        m_player.getDirection(m_player.getStoneTarget());

    if (m_player.moveTo(dir.first, dir.second))
      {
	return (Value::YES);
      }
    return (Value::NO);
  }

  Value AI::troll(Value)
  {
    nope::log::Log(Debug) << "STATE : troll";
    return (Value::NO);
  }

  Value AI::initAI(Value)
  {
    nope::log::Log(Debug) << "STATE : initAI";
    return (Value::NO);
  }
}
