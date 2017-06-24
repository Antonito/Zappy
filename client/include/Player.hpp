#ifndef ZAPPY_PLAYER_HPP_
#define ZAPPY_PLAYER_HPP_

#include <ostream>

namespace zappy
{
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

  private:
  };
  std::ostream &operator<<(std::ostream &, Player::Orientation const &);
}

#endif // !ZAPPY_PLAYER_HPP_
