#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Player::Player()
      : m_mesh(Model::fromObj("./models/player.obj")), m_x(0), m_y(0),
        m_orientation(), m_level(1), m_position(0, 0, 0), m_speed(0, 0, 0),
        m_lastPower(0), m_lastDir(0), m_lastPos(0, 0, 0)
  {
    m_mesh.scale(1.2);
  }

  Player::Player(Player const &that)
      : m_mesh(that.m_mesh), m_x(that.m_x), m_y(that.m_y),
        m_orientation(that.m_orientation), m_level(that.m_level),
        m_position(that.m_position), m_speed(that.m_speed),
        m_lastPower(that.m_lastPower), m_lastDir(that.m_lastDir),
        m_lastPos(that.m_lastPos)
  {
  }

  Player::Player(Player &&that)
      : m_mesh(std::move(that.m_mesh)), m_x(std::move(that.m_x)),
        m_y(std::move(that.m_y)), m_orientation(std::move(that.m_orientation)),
        m_level(std::move(that.m_level)),
        m_position(std::move(that.m_position)),
        m_speed(std::move(that.m_speed)),
        m_lastPower(std::move(that.m_lastPower)),
        m_lastDir(std::move(that.m_lastDir)),
        m_lastPos(std::move(that.m_lastPos))
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
    m_lastPower = that.m_lastPower;
    m_lastDir = that.m_lastDir;
    m_lastPos = that.m_lastPos;
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
    m_lastPower = std::move(that.m_lastPower);
    m_lastDir = std::move(that.m_lastDir);
    m_lastPos = std::move(that.m_lastPos);
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

  glm::vec3 Player::direction() const
  {
    int dir = static_cast<int>(m_orientation) - 1;

    return (glm::vec3(dir == 1 ? -1.0f : dir == 3 ? 1.0f : 0.0f, 0.0f,
                      dir == 0 ? 1.0f : dir == 2 ? -1.0f : 0.0f));
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

  void Player::updatePosition(double sinceLast)
  {
    if (glm::length(m_mesh.position() - m_position) < 0.01f)
      {
	m_mesh.setPosition(m_position);
	m_speed = glm::vec3(0.0f, 0.0f, 0.0f);
      }
    else
      {
	constexpr float alpha = 5.0f;

	glm::vec3 diff = m_position - m_mesh.position();

	m_mesh.translate(alpha * diff * static_cast<float>(sinceLast));
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

  bool Player::isLightUpToDate(std::size_t power, std::size_t dir,
                               glm::vec3 const &pos) const
  {
    bool upToDate = true;

    if (power != m_lastPower)
      {
	m_lastPower = power;
	upToDate = false;
      }

    if (dir != m_lastDir)
      {
	m_lastDir = dir;
	upToDate = false;
      }

    if (pos != m_lastPos)
      {
	m_lastPos = pos;
	upToDate = false;
      }

    return (upToDate);
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
