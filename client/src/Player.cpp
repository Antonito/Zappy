#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Player::Player()
      : m_mesh(Model::fromObj("./models/player.obj")), m_x(0), m_y(0)
  {
    m_mesh.scale(0.2, 0.4, 0.2);
  }

  Player::Player(Player const &that)
      : m_mesh(that.m_mesh), m_x(that.m_x), m_y(that.m_y)
  {
  }

  Player::Player(Player &&that)
      : m_mesh(std::move(that.m_mesh)), m_x(std::move(that.m_x)),
        m_y(std::move(that.m_y))
  {
  }

  Player::~Player()
  {
  }

  Player &Player::operator=(Player const &that)
  {
    if (this == &that)
      return (*this);
    m_mesh = that.m_mesh;
    m_x = that.m_x;
    m_y = that.m_y;
    return (*this);
  }

  Player &Player::operator=(Player &&that)
  {
    if (this == &that)
      return (*this);
    m_mesh = std::move(that.m_mesh);
    m_x = std::move(that.m_x);
    m_y = std::move(that.m_y);
    return (*this);
  }

  void Player::renderOn(Window &win, Camera const &camera) const
  {
    win.draw(camera, m_mesh);
  }

  std::size_t Player::getX() const
  {
    return (m_x);
  }

  std::size_t Player::getY() const
  {
    return (m_y);
  }

  Player::Orientation Player::orientation() const
  {
    return (m_orientation);
  }

  std::size_t Player::level() const
  {
    return (m_level);
  }

  void Player::setOrientation(Player::Orientation orientation)
  {
    m_orientation = orientation;
  }

  void Player::setLevel(std::size_t level)
  {
    m_level = level;
  }

  void Player::setPlayerPosition(std::size_t x, std::size_t y)
  {
    m_x = x;
    m_y = y;
    m_mesh.setPosition(glm::vec3(x, 1.0, y));
  }

  void Player::dropResource(GameMap &map, Resource::Type t)
  {
    map.addResource(m_x, m_y, t);
  }

  void Player::takeResource(GameMap &map, Resource::Type t)
  {
    map.removeResource(m_x, m_y, t);
  }

  std::ostream &operator<<(std::ostream &os, Player::Orientation const &o)
  {
    switch (o)
      {
      case zappy::Player::Orientation::North:
	os << "North";
	break;
      case zappy::Player::Orientation::East:
	os << "East";
	break;
      case zappy::Player::Orientation::South:
	os << "South";
	break;
      case zappy::Player::Orientation::West:
	os << "West";
	break;
      }
    return (os);
  }
}
