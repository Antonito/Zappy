#include "AI.hpp"

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
  };

  static const std::array<std::pair<std::int32_t, std::array<std::int32_t, 6>>,
                          7>
      recipes = {{
          {1, {{1, 0, 0, 0, 0, 0}}},
          {2, {{1, 1, 1, 0, 0, 0}}},
          {2, {{2, 0, 1, 0, 2, 0}}},
          {4, {{1, 1, 2, 0, 1, 0}}},
          {4, {{1, 2, 1, 3, 0, 0}}},
          {6, {{1, 2, 3, 0, 1, 0}}},
          {6, {{2, 2, 2, 2, 2, 1}}},
      }};

  AI::AI(std::string ip, std::uint16_t port)
      : m_actionForState(), m_foodUnit(0),
        m_sock(port, ip, true, network::ASocket::BLOCKING),
        m_curState(State::STARVING), m_curValue(Value::YES)
  {
    if (!m_sock.openConnection())
      {
	throw std::exception();
      }
    initAction();
  }

  AI::~AI()
  {
  }

  std::int32_t AI::checkActivity(fd_set &readfds, fd_set &writefds)
  {
    {
      std::int32_t   rc = -1;
      struct timeval tv;
      std::int32_t   maxFd;

      // Check file descriptors
      do
	{
	  FD_ZERO(&readfds);
	  FD_ZERO(&writefds);
	  tv.tv_sec = 2;
	  tv.tv_usec = 0;

	  // Add Game Server's socket
	  maxFd = m_sock.getSocket();
	  if (!m_cmdToSend.empty())
	    {
	      FD_SET(maxFd, &writefds);
	    }
	  else
	    {
	      FD_SET(maxFd, &readfds);
	    }

	  // Loop over gameServers
	  rc = select(maxFd + 1, &readfds, &writefds, nullptr, &tv);
	}
      while (rc == -1 && errno == EINTR);
      return (rc);
    }
  }

  std::int32_t AI::loop()
  {
    // TODO : CHECK DEAD
    while (1)
      {
	fd_set readfds, writefds;

	std::int32_t const rc = checkActivity(readfds, writefds);
	if (rc < 0)
	  {
	    std::cerr << "log -> select failed :/" << std::endl;
	    return (1);
	  }
	else if (rc > 0)
	  {
	    if (FD_ISSET(m_sock.getSocket(), &readfds))
	      {
		// TODO : real check for split \n commands
		if (treatIncomingData())
		  return (1);
	      }
	    else if (FD_ISSET(m_sock.getSocket(), &writefds))
	      {
		if (treatOutcomingData())
		  return (1);
	      }
	  }
	Value (AI::*funcptr)(Value) = m_actionForState[m_curState];
	m_curValue = (this->*funcptr)(m_curValue);
	m_curState = transitionTable.at(
	    m_curState)[static_cast<std::size_t>(m_curValue)];
      }
  }

  std::int32_t AI::treatIncomingData()
  {
    std::array<char, 512> tmp;
    ssize_t len = 0;

    len = ::read(m_sock.getSocket(), &tmp, 511);
    if (len < 0)
      {
	std::cerr << "log -> read failed" << std::endl;
	return (1);
      }
    else if (len == 0)
      {
	std::cerr << "No more communication with the server :/" << std::endl;
      }
    else
      {
	tmp[static_cast<std::size_t>(len)] = 0;
	m_cmdToRecv.push(std::string(tmp.data()));
      }
    return (0);
  }

  std::int32_t AI::treatOutcomingData()
  {
    // TODO :
    //::write(m_sock.getSocket(), m_cmdToSend.front(),
    // std::strlen(m_cmdToSend.front().data));
    m_cmdToSend.pop();
    return (0);
  }

  void AI::initAction()
  {
    m_actionForState.emplace(State::STARVING, &AI::starving);
    m_actionForState.emplace(State::RECEIVE_MSG, &AI::receiveMsg);
    m_actionForState.emplace(State::MISSING_STONE, &AI::missingStone);
    m_actionForState.emplace(State::MISSING_PLAYER, &AI::missingPlayer);
    m_actionForState.emplace(State::SET_RECIPE, &AI::setRecipe);
    m_actionForState.emplace(State::INCANT, &AI::incant);
    m_actionForState.emplace(State::FOOD_ON_CASE, &AI::foodOnCase);
    m_actionForState.emplace(State::COLLECT_FOOD, &AI::collectFood);
    m_actionForState.emplace(State::FIND_FOOD, &AI::findFood);
    m_actionForState.emplace(State::MOVE_TO_FOOD, &AI::moveToFood);
    m_actionForState.emplace(State::LEVEL, &AI::checkLevel);
    m_actionForState.emplace(State::MOVE_TO_TEAMMATE, &AI::moveToTeammate);
    m_actionForState.emplace(State::ARRIVED, &AI::arrived);
    m_actionForState.emplace(State::FIX_RECIPE, &AI::fixRecipe);
    m_actionForState.emplace(State::STONE_ON_CASE, &AI::stoneOnCase);
    m_actionForState.emplace(State::COLLECT_STONE, &AI::collectStone);
    m_actionForState.emplace(State::FIND_STONE, &AI::findStone);
    m_actionForState.emplace(State::MOVE_TO_STONE, &AI::moveToStone);
    m_actionForState.emplace(State::TROLL, &AI::troll);
  }

  void AI::send(std::string const &msg)
  {
    // broadcast msg to all player
  }

  void AI::move(std::pair<std::int32_t, std::int32_t> coord)
  {
    for (std::int32_t y = 0; y < coord.second; ++y)
      {
	m_cmdToSend.push("Forward\n");
      }
    // TODO : check for Y 'ok' from server
    if (coord.first > 0)
      {
	m_cmdToSend.push("Right\n");
      }
    else
      {
	m_cmdToSend.push("Left\n");
      }
    for (std::int32_t x = 0; x < coord.first; ++x)
      {
	m_cmdToSend.push("Forward\n");
      }
    // TODO : check for X 'ok' from server
  }

  std::int32_t AI::look(std::string const &object)
  {
    // look
    // check if object is in vision
    // return case number of the object , -1 if no object found
  }

  void AI::getCurCase()
  {
    // look
    // fill m_curCase with the stone there is on case
  }

  std::pair<std::int32_t, std::int32_t> const
      AI::direction(std::int32_t caseNumber)
  {
    int32_t x = 0, y = 0, mid = 0;

    for (y = 0; caseNumber > mid + y; ++y)
      {
	mid += 2 * y;
      }
    x = caseNumber - mid;
    std::pair<std::int32_t, std::int32_t> res = {x, y};
    return (res);
  }

  std::array<std::int32_t, 6> const
      AI::diff(std::array<std::int32_t, 6> old,
               std::array<std::int32_t, 6> newTab)
  {
    std::array<std::int32_t, 6> res{};
    for (std::size_t i = 0; i < 6; ++i)
      {
	res[i] = newTab[i] - old[i];
      }
    return (res);
  }

  Value AI::starving(Value value)
  {
    if (m_foodUnit < NB_FOOD_MIN)
      {
	return (Value::YES);
      }
    else if (m_foodUnit < NB_FOOD_NORMAL)
      {
	// TODO : set different starving state
	return (Value::YES);
      }
    else
      {
	return (Value::NO);
      }
  }

  Value AI::receiveMsg(Value value)
  {
  }

  Value AI::missingStone(Value value)
  {
    bool enough = true;

    // TODO: Update inventory
    for (std::size_t i = 0; i < 6; ++i)
      {
	if (m_inventory[i] >= recipes[m_level - 1].second[i])
	  {
	    enough = false;
	    break;
	  }
      }
    if (enough)
      return (Value::NO);
    else
      return (Value::YES);
  }

  Value AI::missingPlayer(Value value)
  {
    std::int32_t nb_players = 0;
    while (nb_players < recipes[m_level - 1].first)
      {
	// TODO: Count nb PLayers on case
	m_cmdToSend.push("Broadcast COME " + std::to_string(m_level) + "\n");
      }
    m_cmdToSend.push("Broadcast GO AWAY \n");
    return (Value::YES);
  }

  Value AI::setRecipe(Value value)
  {
  }

  Value AI::incant(Value value)
  {
    m_cmdToSend.push("Incantation\n");
    // Todo
  }

  Value AI::foodOnCase(Value value)
  {
  }

  Value AI::collectFood(Value value)
  {
  }

  Value AI::findFood(Value value)
  {
  }

  Value AI::moveToFood(Value value)
  {
  }

  Value AI::checkLevel(Value value)
  {
  }

  Value AI::moveToTeammate(Value value)
  {
  }

  Value AI::arrived(Value value)
  {
  }

  Value AI::fixRecipe(Value value)
  {
  }

  Value AI::stoneOnCase(Value value)
  {
  }

  Value AI::collectStone(Value value)
  {
  }

  Value AI::findStone(Value value)
  {
  }

  Value AI::moveToStone(Value value)
  {
  }

  Value AI::troll(Value value)
  {
    std::int32_t number = std::rand() % 5;

    if (number == 0)
      {
	// TODO :send same message to troll others
	return (Value::YES);
      }
    else
      {
	return (Value::NO);
      }
  }
}
