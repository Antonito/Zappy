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
}
