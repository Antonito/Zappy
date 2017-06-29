#ifndef ZAPPY_WINDOW_HPP_
#define ZAPPY_WINDOW_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include "Mesh.hpp"
#include "Shader.hpp"
#include "Camera.hpp"

namespace zappy
{
  class Window
  {
  public:
    Window() = delete;
    explicit Window(unsigned int width, unsigned int height,
                    std::string const &name);
    Window(Window const &) = delete;
    Window(Window &&) = delete;
    ~Window();

    Window &operator=(Window const &) = delete;
    Window &operator=(Window &&) = delete;

    //
    // Event methods
    //
    bool isOpen() const;
    bool pollEvent(sf::Event &event);
    void close();

    //
    // Draw methods
    //
    void setClearColor(float r, float g, float b, float a);
    void clear();
    void useShader(Shader &shader);
    void draw(Camera const &camera, Mesh const &mesh);
    void display();

    //
    // Properties
    //
    unsigned int width() const;
    unsigned int height() const;
    sf::Vector2u size() const;
    sf::Window const &win() const;
    void setCursorVisible(bool visible);
  private:
    sf::Window m_win;
    Shader *m_curShader;
  };
}

#endif // !ZAPPY_WINDOW_HPP_
