#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Window::Window(unsigned int width, unsigned int height,
                 std::string const &name)
      : m_win(sf::VideoMode(width, height), name, sf::Style::Close,
              sf::ContextSettings(24, 8, 0, 4, 5, 0))
  {
    glewExperimental = GL_TRUE;
    glewInit();
  }

  Window::~Window()
  {
  }

  bool Window::isOpen() const
  {
    return (m_win.isOpen());
  }

  bool Window::pollEvent(sf::Event &e)
  {
    return (m_win.pollEvent(e));
  }

  void Window::close()
  {
    m_win.close();
  }

  void Window::setClearColor()
  {
    // TODO: implement
  }

  void Window::clear()
  {
    m_win.setActive();
  }

  void Window::draw(Mesh const &)
  {
    // TODO: implement
  }

  void Window::display()
  {
    m_win.display();
  }
}