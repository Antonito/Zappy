#ifndef ISTATE_HPP_
#define ISTATE_HPP_

#include <iostream>
#include <map>
#include <queue>
#include <array>
#include "AI.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wweak-vtables"
#endif

namespace ai
{
  enum Stone : std::int8_t
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME,
    NB_STONE,
  };

  enum Value : std::int8_t
  {
    LOOP = -1,
    YES = 0,
    NO,
    COME,
    GO_AWAY,
    SEARCH,
    WAINTING,
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

  class IState
  {
  public:
    virtual ~IState()
    {
    }
    virtual void readState(std::queue<std::string> &readQueue) = 0;
    virtual void writeState(std::queue<std::string> &writeQueue) = 0;
    virtual void reset(Value value) = 0;
    virtual Value getResponse() const = 0;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !ISTATE_HPP_

