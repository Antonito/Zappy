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

  void GameMap::renderOn(Window &window, Camera const &camera) const
  {
    for (Tile const &tile : m_tiles)
      {
	tile.renderOn(window, camera);
      }
  }

  void GameMap::setSize(std::size_t x, std::size_t y)
  {
    m_tiles.resize(x * y);
    for (std::size_t _y = 0; _y < y; ++_y)
      {
	for (std::size_t _x = 0; _x < x; ++_x)
	  {
	    constexpr double shift = 1.1;
	    m_tiles[x * _y + _x].setPosition(
	        glm::vec3(shift * _x, 0, shift * _y));
	  }
      }
  }
}
