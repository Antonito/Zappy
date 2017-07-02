#ifndef AI_HPP_
#define AI_HPP_

#include <iostream>
#include <map>
#include <queue>
#include <array>
#include "TCPSocket.hpp"
#include "PlayerInfo.hpp"
#include "NetworkManager.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

#define NB_FOOD_MIN (5)
#define NB_FOOD_NORMAL (15)

namespace ai
{
  enum Value : std::size_t
  {
    YES = 0,
    NO,
    COME,
    GO_AWAY,
    SEARCH,
    WAITING,
    READY,
    END_INCANT,
    NB_VALUE,
  };

  enum State : std::int8_t
  {
    NO_CHANGE = -1,
    DEAD,
    STARVING,
    RECEIVE_MSG,
    MISSING_STONE,
    MISSING_PLAYER,
    SET_RECIPE,
    INCANT,
    FOOD_ON_CASE,
    COLLECT_FOOD,
    FIND_FOOD,
    MOVE_TO_FOOD,
    LEVEL,
    MOVE_TO_TEAMMATE,
    ARRIVED,
    FIX_RECIPE,
    STONE_ON_CASE,
    COLLECT_STONE,
    FIND_STONE,
    MOVE_TO_STONE,
    TROLL,
    INIT_AI,
    NB_STATE,
  };

  class AI
  {
  public:
    AI() = delete;
    explicit AI(std::string const &ip, std::uint16_t port,
                std::string const &teamname);
    AI(AI const &) = delete;
    AI(AI const &&) = delete;
    ~AI();

    AI &operator=(AI const &) = delete;
    AI &operator=(AI const &&) = delete;

    void loop();

  private:
    void initState();

    Value starving(Value v);
    Value receiveMessage(Value v);
    Value missingStone(Value v);
    Value missingPlayer(Value v);
    Value setRecipe(Value v);
    Value incant(Value v);
    Value foodOnCase(Value v);
    Value collectFood(Value v);
    Value findFood(Value v);
    Value moveToFood(Value v);
    Value level(Value v);
    Value moveToTeammate(Value v);
    Value arrived(Value v);
    Value fixRecipe(Value v);
    Value stoneOnCase(Value v);
    Value collectStone(Value v);
    Value findStone(Value v);
    Value moveToStone(Value v);
    Value troll(Value v);

    std::array<Value (AI::*)(Value), State::NB_STATE> m_states;
    State          m_curState;
    Value          m_curValue;
    NetworkManager m_network;
    PlayerInfo     m_player;
    bool           m_alive;

    std::int32_t m_loop;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !AI_HPP_
