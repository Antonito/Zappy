#ifndef ARRIVEDSTATE_HPP_
#define ARRIVEDSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class ArrivedState final : public AState
  {
  public:
    ArrivedState(std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player);
    ArrivedState(ArrivedState const &) = delete;
    ArrivedState(ArrivedState &&) = delete;
    virtual ~ArrivedState();

    ArrivedState &operator=(ArrivedState const &) = delete;
    ArrivedState &operator=(ArrivedState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  private:
    std::int32_t m_counter;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !ARRIVEDSTATE_HPP_
