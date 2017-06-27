#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Player::Player()
  {
  }

  Player::Player(Player const &that)
  {
    // TODO: implement
    (void)that;
  }

  Player::Player(Player &&that)
  {
    // TODO: implement
    (void)that;
  }

  Player::~Player()
  {
  }

  Player &Player::operator=(Player const &that)
  {
    if (this == &that)
      return (*this);
    return (*this);
  }

  Player &Player::operator=(Player &&that)
  {
    if (this == &that)
      return (*this);
    return (*this);
  }

  void Player::renderOn(Window &) const
  {
    // TODO: implement
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
