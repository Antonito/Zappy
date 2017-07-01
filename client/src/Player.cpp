#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Player::Player()
      : m_mesh(Model::fromObj("./models/player.obj")), m_x(0), m_y(0),
        m_orientation(), m_level(1), m_position(0, 0, 0), m_speed(0, 0, 0)
  {
    m_mesh.scale(1.2);
  }

  Player::Player(Player const &that)
      : m_mesh(that.m_mesh), m_x(that.m_x), m_y(that.m_y),
        m_orientation(that.m_orientation), m_level(that.m_level),
        m_position(that.m_position), m_speed(that.m_speed)
  {
  }

  Player::Player(Player &&that)
      : m_mesh(std::move(that.m_mesh)), m_x(std::move(that.m_x)),
        m_y(std::move(that.m_y)), m_orientation(std::move(that.m_orientation)),
        m_level(std::move(that.m_level)),
        m_position(std::move(that.m_position)),
        m_speed(std::move(that.m_speed))
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
    m_orientation = that.m_orientation;
    m_level = that.m_level;
    m_position = that.m_position;
    m_speed = that.m_speed;
    return (*this);
  }

  Player &Player::operator=(Player &&that)
  {
    if (this == &that)
      return (*this);
    m_mesh = std::move(that.m_mesh);
    m_x = std::move(that.m_x);
    m_y = std::move(that.m_y);
    m_orientation = std::move(that.m_orientation);
    m_level = std::move(that.m_level);
    m_position = std::move(that.m_position);
    m_speed = std::move(that.m_speed);
    return (*this);
  }

  void Player::renderOn(Window &win, Camera const &camera) const
  {
    win.draw(camera, m_mesh);
  }

  glm::vec4 const &Player::color() const
  {
    return (m_mesh.color());
  }

  glm::vec3 const &Player::position() const
  {
    return (m_mesh.position());
  }

  std::size_t Player::getX() const
  {
    return (m_x);
  }

  std::size_t Player::getY() const
  {
    return (m_y);
  }

  Player::Orientation const &Player::orientation() const
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
    m_mesh.setRotation(
        glm::angleAxis(static_cast<GLfloat>(
                           -M_PI / 2.0 * (static_cast<int>(orientation) - 1)),
                       glm::vec3(0, 1, 0)));
  }

  void Player::setLevel(std::size_t level)
  {
    m_level = level;
  }

  void Player::setPlayerPosition(std::size_t x, std::size_t y)
  {
    m_x = x;
    m_y = y;
    m_position = glm::vec3(-static_cast<float>(x), 0.5f, y);
  }

  void Player::updatePosition()
  {
    if (glm::length(m_mesh.position() - m_position) < 0.01f)
      {
	m_mesh.setPosition(m_position);
	m_speed = glm::vec3(0.0f, 0.0f, 0.0f);
      }
    else
      {
	constexpr float alpha = 0.1f;

	glm::vec3 diff = m_position - m_mesh.position();

	m_mesh.translate(alpha * diff);
      }
  }

  void Player::dropResource(GameMap &map, Resource::Type t)
  {
    map.addResource(m_x, m_y, t);
  }

  void Player::takeResource(GameMap &map, Resource::Type t)
  {
    map.removeResource(m_x, m_y, t);
  }

  void Player::setColor(glm::vec4 const &color)
  {
    m_mesh.setColor(color);
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
