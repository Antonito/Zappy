#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Window::Window(unsigned int width, unsigned int height,
                 std::string const &name)
      : m_win(sf::VideoMode(width, height), name, sf::Style::Close,
              sf::ContextSettings(24, 8, 0, 3, 3, 0)),
        m_curShader(nullptr)
  {
    glewExperimental = GL_TRUE;
    glewInit();

    glClearDepth(100000.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
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

  void Window::setClearColor(float r, float g, float b, float a)
  {
    glClearColor(r, g, b, a);
  }

  void Window::clear()
  {
    m_win.setActive();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  }

  void Window::useShader(Shader &shader)
  {
    shader.bind();
    m_curShader = &shader;
  }

  void Window::draw(Camera const &camera, Mesh const &mesh)
  {
    assert(m_curShader != nullptr);

    m_curShader->updateTransform(camera.getViewProjection() *
                                 mesh.fullTransform());
    m_curShader->updateShadowMat(mesh.fullTransform());
    m_curShader->updateColor(mesh.color());
    mesh.model().render();
  }

  void Window::display()
  {
    m_win.display();
  }

  unsigned int Window::width() const
  {
    return (m_win.getSize().x);
  }

  unsigned int Window::height() const
  {
    return (m_win.getSize().y);
  }

  sf::Vector2u Window::size() const
  {
    return (m_win.getSize());
  }

  sf::Window const &Window::win() const
  {
    return (m_win);
  }

  void Window::setCursorVisible(bool visible)
  {
    m_win.setMouseCursorVisible(visible);
  }
}
