#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  GraphicClient::GraphicClient(unsigned int width, unsigned int height,
                               std::string const &windowName,
                               std::uint16_t port, std::string const &name,
                               std::string const &machine)
      : m_win(sf::VideoMode(width, height), windowName), m_port(port),
        m_name(name), m_machine(machine)
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
  // Sending commands
  //

  void GraphicClient::askMapSize() const
  {
    sendCommand("msz\n");
  }

  void GraphicClient::askTileContent(std::size_t x, std::size_t y) const
  {
    std::stringstream ss;

    ss << "bct " << x << ' ' << y << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askMapContent() const
  {
    sendCommand("mct\n");
  }

  void GraphicClient::askTeamNames() const
  {
    sendCommand("tna\n");
  }

  void GraphicClient::askPlayerPosition(std::size_t playerId) const
  {
    std::stringstream ss;

    ss << "ppo #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askPlayerLevel(std::size_t playerId) const
  {
    std::stringstream ss;

    ss << "plv #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askPlayerInventory(std::size_t playerId) const
  {
    std::stringstream ss;

    ss << "pin #" << playerId << '\n';
    sendCommand(ss.str());
  }

  void GraphicClient::askTimeUnit() const
  {
    sendCommand("sgt\n");
  }

  void GraphicClient::askTimeUnitModification(std::size_t unit) const
  {
    std::stringstream ss;

    ss << "sst " << unit << '\n';
    sendCommand(ss.str());
  }
}