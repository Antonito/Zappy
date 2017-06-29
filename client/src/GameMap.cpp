#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  GameMap::GameMap() : m_tiles(), m_height(0), m_x(0), m_y(0)
  {
  }

  GameMap::GameMap(GameMap const &that)
      : m_tiles(that.m_tiles), m_height(that.m_height), m_x(that.m_x),
        m_y(that.m_y)
  {
  }

  GameMap::GameMap(GameMap &&that)
      : m_tiles(std::move(that.m_tiles)), m_height(std::move(that.m_height)),
        m_x(std::move(that.m_x)), m_y(std::move(that.m_y))
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
    m_height = that.m_height;
    m_x = that.m_x;
    m_y = that.m_y;
    return (*this);
  }

  GameMap &GameMap::operator=(GameMap &&that)
  {
    if (this == &that)
      return (*this);
    m_tiles = std::move(that.m_tiles);
    m_height = std::move(that.m_height);
    m_x = std::move(that.m_x);
    m_y = std::move(that.m_y);
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
    m_x = x;
    m_y = y;
    for (std::size_t _y = 0; _y < y; ++_y)
      {
	for (std::size_t _x = 0; _x < x; ++_x)
	  {
	    m_tiles[x * _y + _x].setPosition(glm::vec3(_x, 0, _y));
	  }
      }
  }

  void GameMap::addResource(std::size_t x, std::size_t y, Resource::Type type,
                            std::size_t n)
  {
    m_tiles[m_x * y + x].addResource(type, n);
  }

  void GameMap::removeResource(std::size_t x, std::size_t y,
                               Resource::Type type, std::size_t n)
  {
    m_tiles[m_x * y + x].removeResource(type, n);
  }

  void GameMap::setResource(std::size_t x, std::size_t y, Resource::Type type,
                            std::size_t n)
  {
    m_tiles[m_x * y + x].setResource(type, n);
  }
}
