#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  GameMap::GameMap() : m_tiles()
  {
  }

  GameMap::GameMap(GameMap const &that) : m_tiles(that.m_tiles)
  {
  }

  GameMap::GameMap(GameMap &&that) : m_tiles(std::move(that.m_tiles))
  {
  }

  GameMap::~GameMap()
  {
  }

  GameMap &GameMap::operator=(GameMap const &that)
  {
    if (this == &that)
      return (*this);
    m_tiles = that.m_tiles;
    return (*this);
  }

  GameMap &GameMap::operator=(GameMap &&that)
  {
    if (this == &that)
      return (*this);
    m_tiles = std::move(that.m_tiles);
    return (*this);
  }
}
