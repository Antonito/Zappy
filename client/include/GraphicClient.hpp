#ifndef ZAPPY_GRAPHICCLIENT_HPP_
#define ZAPPY_GRAPHICCLIENT_HPP_

#include <SFML/Graphics.hpp>

namespace zappy
{
  class GraphicClient
  {
  public:
    GraphicClient() = delete;
    GraphicClient(GraphicClient const &) = delete;
    explicit GraphicClient(unsigned int width, unsigned int height,
                           std::string const &windowName, std::uint16_t port,
                           std::string const &name,
                           std::string const &machine);
    GraphicClient(GraphicClient &&) = delete;
    ~GraphicClient();

    GraphicClient &operator=(GraphicClient const &) = delete;
    GraphicClient &operator=(GraphicClient &&) = delete;

    void launch();

  private:
    sf::RenderWindow m_win;
    std::uint16_t m_port;
    std::string m_name;
    std::string m_machine;
  };
}

#endif // !ZAPPY_GRAPHICCLIENT_HPP_