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

  private:
    std::vector<Tile> m_tiles;
    float             m_height;
  };
}

#endif // !ZAPPY_GAMEMAP_HPP_
