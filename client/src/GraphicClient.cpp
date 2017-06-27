#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  GraphicClient::GraphicClient(unsigned int width, unsigned int height,
                               std::string const &windowName,
                               std::uint16_t port, std::string const &name,
                               std::string const &machine)
      : m_win(width, height, windowName), m_port(port), m_name(name),
        m_machine(machine), m_map(), m_players()
  {
  }

  GraphicClient::~GraphicClient()
  {
  }

  void GraphicClient::launch()
  {
    Shader shader("./shaders/test");
    // Model  test = Model::fromObj("./models/cube.obj");

    std::vector<glm::vec3> points = {
        {-0.5, -1.0, -0.5}, {0.0, 1.0, 0.5}, {0.5, -1.0, -0.5}};
    std::vector<std::uint32_t> index = {0, 1, 2};

    Model test2(IndicesElement<glm::vec3>(points, index),
                IndicesElement<glm::vec2>(), IndicesElement<glm::vec3>());
    Mesh cube(test2);

    m_win.setClearColor(0.1, 0.1, 0.2, 1.0);
    shader.bind();

    //     std::vector<GLfloat> pts = {-1.0f, -1.0f, 0.0f,
    //    1.0f, -1.0f, 0.0f,
    //    0.0f,  1.0f, 0.0f};

    //     GLuint vertexbuf;

    //     glGenBuffers(1, &vertexbuf);

    //     glBindBuffer(GL_ARRAY_BUFFER, vertexbuf);

    //     glBufferData(GL_ARRAY_BUFFER, pts.size() * sizeof(pts[0]), &pts[0],
    //     GL_STATIC_DRAW);

    while (m_win.isOpen())
      {
	// Manage user inputs
	sf::Event event;

	while (m_win.pollEvent(event))
	  {
	    this->dispatch(event);
	  }

	// Execute at most "maxCommand" commands
	constexpr std::size_t maxCommand = 50;
	std::size_t           i = 0;

	while (i < maxCommand && this->execCommand())
	  {
	    ++i;
	  }

	// Clear the window
	m_win.clear();

	// m_map.renderOn(m_win);

	// for (Player const &player : m_players)
	//   {
	//     player.renderOn(m_win);
	//   }

	// glEnableVertexAttribArray(0);

	// glBindBuffer(GL_ARRAY_BUFFER, vertexbuf);

	// glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, nullptr);

	// glDrawArrays(GL_TRIANGLES, 0, 3);
	// glDisableVertexAttribArray(0);

	// m_win.draw(cube);

	cube.model().render();

	// Display the window
	m_win.display();
      }
  }

  //
  // Event
  //
  void GraphicClient::dispatch(sf::Event const &e)
  {
    if (e.type == sf::Event::Closed)
      {
	m_win.close();
	return;
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
    std::string cmd = "";

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
    nope::log::Log(Info) << "Requesting the map size";
    sendCommand("msz\n");
  }

  void GraphicClient::askTileContent(std::size_t x, std::size_t y)
  {
    std::stringstream ss;

    nope::log::Log(Debug) << "Requesting a tile content (" << x << ", " << y
                          << ')';
    ss << "bct " << x << ' ' << y << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askMapContent()
  {
    nope::log::Log(Debug) << "Requesting the map content";
    sendCommand("mct\n");
  }

  void GraphicClient::askTeamNames()
  {
    nope::log::Log(Info) << "Requesting the team names";
    sendCommand("tna\n");
  }

  void GraphicClient::askPlayerPosition(std::size_t playerId)
  {
    std::stringstream ss;

    nope::log::Log(Debug) << "Requesting a player position (" << playerId
                          << ')';
    ss << "ppo #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askPlayerLevel(std::size_t playerId)
  {
    std::stringstream ss;

    nope::log::Log(Debug) << "Requesting a player level (" << playerId << ')';
    ss << "plv #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askPlayerInventory(std::size_t playerId)
  {
    std::stringstream ss;

    nope::log::Log(Debug) << "Requesting a player inventory (" << playerId
                          << ')';
    ss << "pin #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askTimeUnit()
  {
    nope::log::Log(Info) << "Requesting the time unit";
    sendCommand("sgt\n");
  }

  void GraphicClient::askTimeUnitModification(std::size_t unit)
  {
    std::stringstream ss;

    nope::log::Log(Info) << "Requesting a time unit change to " << unit;
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

    nope::log::Log(Info) << "Received map size (" << x << ", " << y << ')';
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

    nope::log::Log(Debug) << "Received tile content (" << x << ", " << y
                          << ") [" << food << ", " << linemate << ", "
                          << deraumere << ", " << sibur << ", " << mendiane
                          << ", " << phiras << ", " << thystame << ']';
    // TODO: set the actual values
  }

  void GraphicClient::teamNames(std::string const &data)
  {
    std::istringstream is(data);

    std::string name = parseTeamName(is);

    checkEmpty(is);

    nope::log::Log(Info) << "Received a team name: " << name;

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

    // clang-format off
    nope::log::Log(Info) << "A new player connected:"
                            "\n\tId:\t\t" << playerId
			 << "\n\tPosition:\t(" << x << ", " << y << ")"
			    "\n\tOrientation:\t" << orientation
                         << "\n\tLevel:\t\t" << level
			 << "\n\tTeam:\t\t" << team;
    // clang-format on

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

    nope::log::Log(Debug) << "Received player " << playerId << " position: ("
                          << x << ", " << y << ") (" << orientation << ")";

    // TODO: set the actual values
  }

  void GraphicClient::playerLevel(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t level = parseInt(is);

    nope::log::Log(Debug) << "Received player " << playerId
                          << " level: " << level;

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

    nope::log::Log(Debug) << "Received player " << playerId << " inventory: ("
                          << x << ", " << y << ") [" << food << ", "
                          << linemate << ", " << deraumere << ", " << sibur
                          << ", " << mendiane << ", " << phiras << ", "
                          << thystame << ']';

    // TODO: set the actual values
  }

  void GraphicClient::eject(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "Player " << playerId
                          << " explused others players";

    // TODO: set the actual values
  }

  void GraphicClient::broadcast(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::string message = parseMessage(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "Player " << playerId
                          << " broadcasted the following message:\n\""
                          << message << '\"';

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

    // Create a scope to log the message imediatly after
    {
      // Auto needed because it can be LogMessage or EmptyLogger
      auto &&msg = nope::log::Log(Debug);

      msg << "Player " << playerId << " launched incantation level " << level
          << " in (" << x << ", " << y << ") for " << otherPlayers[0];

      for (std::size_t i = 1; i < otherPlayers.size(); ++i)
	{
	  msg << ", " << otherPlayers[i];
	}
    }

    // TODO: set the actual values
  }

  void GraphicClient::endOfIncantation(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t x = parseInt(is);
    std::size_t y = parseInt(is);
    std::size_t result = parseInt(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "End of the incantation in (" << x << ", " << y
                          << "), result is " << result;

    // TODO: set the actual values
  }

  void GraphicClient::layAnEgg(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "Player " << playerId << " layed an egg";

    // TODO: set the actual values
  }

  void GraphicClient::dropResource(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t resource = parseInt(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "Player " << playerId << " droped a resource ("
                          << resource << ')';

    // TODO: set the actual values
  }

  void GraphicClient::takeResource(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);
    std::size_t resource = parseInt(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "Player " << playerId << " took a resource ("
                          << resource << ')';

    // TODO: set the actual values
  }

  void GraphicClient::starved(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t playerId = parsePlayerId(is);

    checkEmpty(is);

    nope::log::Log(Info) << "Player " << playerId << " starved";

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

    nope::log::Log(Debug) << "The egg " << eggId << " was layed by the player "
                          << playerId << " in (" << x << ", " << y << ')';

    // TODO: set the actual values
  }

  void GraphicClient::eggHatching(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);

    checkEmpty(is);

    nope::log::Log(Debug) << "The egg " << eggId << " hatched";

    // TODO: set the actual values
  }

  void GraphicClient::playerConnectedForEgg(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);

    checkEmpty(is);

    nope::log::Log(Info) << "A player connected for the egg " << eggId;

    // TODO: set the actual values
  }

  void GraphicClient::hatchedEggStarved(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t eggId = parsePlayerId(is);

    checkEmpty(is);

    nope::log::Log(Info) << "The hatched egg " << eggId << " starved";

    // TODO: set the actual values
  }

  void GraphicClient::timeUnit(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t unit = parseInt(is);

    checkEmpty(is);

    nope::log::Log(Info) << "The time unit is now " << unit;

    // TODO: set the actual values
  }

  void GraphicClient::endOfGame(std::string const &data)
  {
    std::istringstream is(data);

    std::size_t winner = parseInt(is);

    checkEmpty(is);

    nope::log::Log(Info) << "End of the game, winner team is " << winner;

    // TODO: set the actual values
  }

  void GraphicClient::serverMessage(std::string const &data)
  {
    std::istringstream is(data);

    std::string message = parseMessage(is);

    checkEmpty(is);

    nope::log::Log(Info) << "Server message: " << message;

    // TODO: set the actual values
  }

  void GraphicClient::unknownCommand(std::string const &data)
  {
    std::istringstream is(data);

    checkEmpty(is);

    nope::log::Log(Warning) << "The server received an unknown command";

    // TODO: set the actual values
  }

  void GraphicClient::badParameter(std::string const &data)
  {
    std::istringstream is(data);

    checkEmpty(is);

    nope::log::Log(Warning) << "The server received a bad command parameter";

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
