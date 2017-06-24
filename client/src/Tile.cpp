#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Tile::Tile()
  {
  }

  Tile::Tile(Tile const &that)
  {
    // TODO: implement
    (void)that;
  }

  Tile::Tile(Tile &&that)
  {
    // TODO: implement
    (void)that;
  }

  Tile::~Tile()
  {
  }

  Tile &Tile::operator=(Tile const &that)
  {
    if (this == &that)
      return (*this);
    return (*this);
  }

  Tile &Tile::operator=(Tile &&that)
  {
    if (this == &that)
      return (*this);
    return (*this);
  }
}
