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

  bool GraphicClient::receiveCommand(std::string &command)
  {
    // TODO: implement
    (void)command;
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
  }

  void GraphicClient::mapContent(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::teamNames(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::newPlayer(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::playerPosition(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::playerLevel(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::playerInventory(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::ejected(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::broadcast(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::launchIncantation(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::endOfIncantation(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::layAnEgg(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::dropResource(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::takeResource(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::starved(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::eggLayed(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::eggHatching(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::playerConnectedForEgg(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::hatchedEggStarved(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::timeUnit(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::endOfGame(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::serverMessage(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::unknownCommand(std::string const &data)
  {
    std::istringstream is(data);
  }

  void GraphicClient::badParameter(std::string const &data)
  {
    std::istringstream is(data);
  }
}
