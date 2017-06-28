#ifndef MOVETOSTONESTATE_HPP_
#define MOVETOSTONESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class MoveToStoneState final : public AState
  {
  public:
    MoveToStoneState(std::map<BasicState, IState *> &states);
    MoveToStoneState(MoveToStoneState const &) = delete;
    MoveToStoneState(MoveToStoneState &&) = delete;
    virtual ~MoveToStoneState();

    MoveToStoneState &operator=(MoveToStoneState const &) = delete;
    MoveToStoneState &operator=(MoveToStoneState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !MOVETOSTONESTATE_HPP_

