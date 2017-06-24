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
}