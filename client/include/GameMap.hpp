#ifndef ZAPPY_GAMEMAP_HPP_
#define ZAPPY_GAMEMAP_HPP_

#include <vector>
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

  private:
    std::vector<Tile> m_tiles;
  };
}

#endif // !ZAPPY_GAMEMAP_HPP_
