#ifndef ZAPPY_TILE_HPP_
#define ZAPPY_TILE_HPP_

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

  private:
  };
}

#endif // !ZAPPY_TILE_HPP_
