#ifndef MOVETOFOODSTATE_HPP_
#define MOVETOFOODSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class MoveToFoodState final : public AState
  {
  public:
    MoveToFoodState(std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player);
    MoveToFoodState(MoveToFoodState const &) = delete;
    MoveToFoodState(MoveToFoodState &&) = delete;
    virtual ~MoveToFoodState();

    MoveToFoodState &operator=(MoveToFoodState const &) = delete;
    MoveToFoodState &operator=(MoveToFoodState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    std::pair<std::int32_t, std::int32_t> m_direction;
    bool m_first;
    bool m_second;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !MOVETOFOODSTATE_HPP_
