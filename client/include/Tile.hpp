#ifndef ZAPPY_TILE_HPP_
#define ZAPPY_TILE_HPP_

#include "Window.hpp"

namespace zappy
{
  class Tile
  {
  public:
    Tile();
    Tile(Tile const &);
    Tile(Tile &&);
    ~Tile();

    Tile &operator=(Tile const &);
    Tile &operator=(Tile &&);

    void renderOn(Window &window) const;
  private:
  };
}

#endif // !ZAPPY_TILE_HPP_
