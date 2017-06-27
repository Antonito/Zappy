#ifndef ZAPPY_WINDOW_HPP_
#define ZAPPY_WINDOW_HPP_

#include <string>
#include <SFML/Graphics.hpp>
#include "Mesh.hpp"

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
    void setClearColor(); // TODO: define the arguments
    void clear();
    void draw(Mesh const &mesh);
    void display();

  private:
    sf::Window m_win;
  };
}

#endif // !ZAPPY_WINDOW_HPP_
