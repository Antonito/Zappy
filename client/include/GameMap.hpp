#ifndef ZAPPY_GAMEMAP_HPP_
#define ZAPPY_GAMEMAP_HPP_

#include <vector>
#include "Window.hpp"
#include "Tile.hpp"

namespace zappy
{
  class GameMap
  {
  public:
    GameMap();
    GameMap(GameMap const &);
    GameMap(GameMap &&);
    ~GameMap();

    GameMap &operator=(GameMap const &);
    GameMap &operator=(GameMap &&);

    void renderOn(Window &window, Camera const &camera) const;
    void setSize(std::size_t x, std::size_t y);

    void addResource(std::size_t x, std::size_t y, Resource::Type type,
                     std::size_t n = 1);
    void removeResource(std::size_t x, std::size_t y, Resource::Type type,
                        std::size_t n = 1);
    void setResource(std::size_t x, std::size_t y, Resource::Type type,
                        std::size_t n);
  private:
    std::vector<Tile> m_tiles;
    float             m_height;
    std::size_t       m_x;
    std::size_t       m_y;
  };
}

#endif // !ZAPPY_GAMEMAP_HPP_
