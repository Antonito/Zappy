#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  GraphicClient::GraphicClient(unsigned int width, unsigned int height,
                               std::string const &windowName,
                               std::uint16_t port, std::string const &name,
                               std::string const &machine)
      : m_win(sf::VideoMode(width, height), windowName), m_port(port),
        m_name(name), m_machine(machine), m_map(), m_players()
  {
  }

  GraphicClient::~GraphicClient()
  {
  }

  void GraphicClient::launch()
  {
    while (m_win.isOpen())
      {
	sf::Event event;

	while (m_win.pollEvent(event))
	  {
	    if (event.type == sf::Event::Closed)
	      {
		m_win.close();
	      }
	  }
	m_win.clear();
	m_win.display();
      }
  }

  //
  // Networking methods
  //

  void GraphicClient::sendCommand(std::string const &command)
  {
    // TODO: implement
    (void)command;
  }

  bool GraphicClient::receiveCommand(std::string &command, std::string &args)
  {
    // TODO: replace this line by the network input
    std::string cmd = "msz 12 14\n";

    if (cmd.length() == 0)
      {
	return (false);
      }

    // Some validity checks
    if (cmd.length() < 4)
      {
	throw std::invalid_argument("Invalid command (command is too short)");
      }

    if (cmd[3] != '\n' && cmd[3] != ' ')
      {
	throw std::invalid_argument("Invalid command (invalid character)");
      }

    if (cmd.back() != '\n')
      {
	throw std::invalid_argument(
	    "Invalid command (not terminated by a newline character)");
      }

    // Remove the '\n'
    cmd.pop_back();

    command = cmd.substr(0, 3);
    args = cmd.substr(4);

    return (true);
  }

  bool GraphicClient::execCommand()
  {
    using first_t = std::string;
    using second_t = void (GraphicClient::*)(std::string const &);

// Disable warning about exit time destructor for this static array
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wexit-time-destructors"
#endif // !__clang__

    static std::array<std::pair<first_t, second_t>, 24> funcs = {
        {{"msz", &GraphicClient::mapSize},
         {"bct", &GraphicClient::tileContent},
         {"tna", &GraphicClient::teamNames},
         {"pnw", &GraphicClient::newPlayer},
         {"ppo", &GraphicClient::playerPosition},
         {"plv", &GraphicClient::playerLevel},
         {"pin", &GraphicClient::playerInventory},
         {"pex", &GraphicClient::eject},
         {"pbc", &GraphicClient::broadcast},
         {"pic", &GraphicClient::launchIncantation},
         {"pie", &GraphicClient::endOfIncantation},
         {"pfk", &GraphicClient::layAnEgg},
         {"pdr", &GraphicClient::dropResource},
         {"pgr", &GraphicClient::takeResource},
         {"pdi", &GraphicClient::starved},
         {"enw", &GraphicClient::eggLayed},
         {"eht", &GraphicClient::eggHatching},
         {"ebo", &GraphicClient::playerConnectedForEgg},
         {"edi", &GraphicClient::hatchedEggStarved},
         {"sgt", &GraphicClient::timeUnit},
         {"seg", &GraphicClient::endOfGame},
         {"smg", &GraphicClient::serverMessage},
         {"suc", &GraphicClient::unknownCommand},
         {"sbp", &GraphicClient::badParameter}}};

// Re-enable the warning
#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

    std::string command;
    std::string args;

    if (receiveCommand(command, args))
      {
	for (std::pair<first_t, second_t> const &p : funcs)
	  {
	    if (command == p.first)
	      {
		(this->*p.second)(args);
		return (true);
	      }
	  }
	throw std::invalid_argument("Unknown command");
      }
    return (false);
  }

  //
  // Sending commands
  //

  void GraphicClient::askMapSize()
  {
    sendCommand("msz\n");
  }

  void GraphicClient::askTileContent(std::size_t x, std::size_t y)
  {
    std::stringstream ss;

    ss << "bct " << x << ' ' << y << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askMapContent()
  {
    sendCommand("mct\n");
  }

  void GraphicClient::askTeamNames()
  {
    sendCommand("tna\n");
  }

  void GraphicClient::askPlayerPosition(std::size_t playerId)
  {
    std::stringstream ss;

    ss << "ppo #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askPlayerLevel(std::size_t playerId)
  {
    std::stringstream ss;

    ss << "plv #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askPlayerInventory(std::size_t playerId)
  {
    std::stringstream ss;

    ss << "pin #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askTimeUnit()
  {
    sendCommand("sgt\n");
  }

  void GraphicClient::askTimeUnitModification(std::size_t unit)
  {
    std::stringstream ss;

    ss << "sst " << unit << '\n';
    sendCommand(ss.str());
  }

  //
  // Received command
  //
  void GraphicClient::mapSize(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::tileContent(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);

    std::size_t food = parseInt(is);
    std::size_t linemate = parseInt(is);
    std::size_t deraumere = parseInt(is);
    std::size_t sibur = parseInt(is);
    std::size_t mendiane = parseInt(is);
    std::size_t phiras = parseInt(is);
    std::size_t thystame = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::teamNames(std::string const &data)
  {
    std::istringstream is(data);

    std::string name = parseTeamName(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::newPlayer(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t         playerId = parsePlayerId(is);
    std::size_t         x = parseInt(is);
    std::size_t         y = parseInt(is);
    Player::Orientation orientation = parseOrientation(is);
    std::size_t         level = parseInt(is);
    std::string         team = parseTeamName(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::playerPosition(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t         playerId = parsePlayerId(is);
    std::size_t         x = parseInt(is);
    std::size_t         y = parseInt(is);
    Player::Orientation orientation = parseOrientation(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::playerLevel(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t level = parseInt(is);

    // TODO: set the actual values
  }

  void GraphicClient::playerInventory(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);

    std::size_t food = parseInt(is);
    std::size_t linemate = parseInt(is);
    std::size_t deraumere = parseInt(is);
    std::size_t sibur = parseInt(is);
    std::size_t mendiane = parseInt(is);
    std::size_t phiras = parseInt(is);
    std::size_t thystame = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::eject(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::broadcast(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::string message = parseMessage(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::launchIncantation(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);
    std::size_t level = parseInt(is);
    std::size_t playerId = parsePlayerId(is);

    std::vector<std::size_t> otherPlayers;

    otherPlayers.push_back(parsePlayerId(is));

    while (is)
      {
	otherPlayers.push_back(parsePlayerId(is));
      }

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::endOfIncantation(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);
    std::size_t level = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::layAnEgg(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::dropResource(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t resource = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::takeResource(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t resource = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::starved(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::eggLayed(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);
    std::size_t playerId = parsePlayerId(is);
    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::eggHatching(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::playerConnectedForEgg(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::hatchedEggStarved(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::timeUnit(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t unit = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::endOfGame(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t winner = parseInt(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::serverMessage(std::string const &data)
  {
    std::istringstream is(data);

    std::string message = parseMessage(is);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::unknownCommand(std::string const &data)
  {
    std::istringstream is(data);

    checkEmpty(is);

    // TODO: set the actual values
  }

  void GraphicClient::badParameter(std::string const &data)
  {
    std::istringstream is(data);

    checkEmpty(is);

    // TODO: set the actual values
  }

  //
  // Command parsing
  //

  std::size_t GraphicClient::parseInt(std::istringstream &is)
  {
    std::size_t res = 0;
    char        c;

    if (!is || is.peek() == ' ')
      {
	throw std::invalid_argument("Invalid character (expected a digit)");
      }

    while (is.get(c) && c != ' ')
      {
	if (std::isdigit(c) == false)
	  {
	    throw std::invalid_argument(
	        "Invalid character (expected a digit)");
	  }
	res = 10 * res + static_cast<std::size_t>(c - '0');
      }
    return (res);
  }

  std::size_t GraphicClient::parsePlayerId(std::istringstream &is)
  {
    std::size_t res = 0;
    char        c;

    if (!is || !is.get(c) || c != '#')
      {
	throw std::invalid_argument("Invalid character (expected a '#')");
      }

    while (is.get(c) && c != ' ')
      {
	if (std::isdigit(c) == false)
	  {
	    throw std::invalid_argument(
	        "Invalid character (expected a digit)");
	  }
	res = 10 * res + static_cast<std::size_t>(c - '0');
      }

    if (c == ' ')
      {
	is.unget();
      }
    return (res);
  }

  Player::Orientation GraphicClient::parseOrientation(std::istringstream &is)
  {
    std::size_t orientation = parseInt(is);

    if (orientation < 1 || orientation > 4)
      {
	throw std::invalid_argument("Invalid orientation");
      }
    return (static_cast<Player::Orientation>(orientation));
  }

  std::string GraphicClient::parseTeamName(std::istringstream &is)
  {
    std::string res;
    char        c;

    if (!is || is.peek() == ' ')
      {
	throw std::invalid_argument("Invalid character (expected a digit)");
      }

    while (is.get(c) && c != ' ')
      {
	res += c;
      }

    return (res);
  }

  std::string GraphicClient::parseMessage(std::istringstream &is)
  {
    return (is.str());
  }

  void GraphicClient::checkEmpty(std::istringstream const &is)
  {
    if (is)
      {
	throw std::invalid_argument("Too many argument for this command");
      }
  }
}
