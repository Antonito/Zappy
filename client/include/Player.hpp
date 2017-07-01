#ifndef ZAPPY_PLAYER_HPP_
#define ZAPPY_PLAYER_HPP_

#include <ostream>
#include "Mesh.hpp"
#include "GameMap.hpp"

namespace zappy
{
  class Window;

  class Player
  {
  public:
    enum class Orientation
    {
      North = 1,
      East = 2,
      South = 3,
      West = 4

    };

    Player();
    Player(Player const &);
    Player(Player &&);
    ~Player();

    Player &operator=(Player const &);
    Player &operator=(Player &&);

    void renderOn(Window &window, Camera const &camera) const;

    glm::vec4 const &  color() const;
    glm::vec3 const &  position() const;
    std::size_t        getX() const;
    std::size_t        getY() const;
    Orientation const &orientation() const;
    std::size_t        level() const;

    void setOrientation(Orientation orientation);
    void setLevel(std::size_t level);
    void setColor(glm::vec4 const &color);

    void setPlayerPosition(std::size_t x, std::size_t y);
    void updatePosition(double sinceLast);
    void dropResource(GameMap &map, Resource::Type t);
    void takeResource(GameMap &map, Resource::Type t);

    bool isLightUpToDate(std::size_t power, std::size_t dir,
                         glm::vec3 const &pos) const;

  private:
    Mesh        m_mesh;
    std::size_t m_x;
    std::size_t m_y;
    Orientation m_orientation;
    std::size_t m_level;
    glm::vec3   m_position;
    glm::vec3   m_speed;

    mutable std::size_t m_lastPower;
    mutable std::size_t m_lastDir;
    mutable glm::vec3   m_lastPos;
  };

  std::ostream &operator<<(std::ostream &, Player::Orientation const &);
}

#endif // !ZAPPY_PLAYER_HPP_
