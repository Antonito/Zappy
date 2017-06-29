#ifndef MOVETOTEAMMATESTATE_HPP_
#define MOVETOTEAMMATESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class MoveToTeammateState final : public AState
  {
  public:
    MoveToTeammateState(std::map<BasicState, std::unique_ptr<IState>> &states);
    MoveToTeammateState(MoveToTeammateState const &) = delete;
    MoveToTeammateState(MoveToTeammateState &&) = delete;
    virtual ~MoveToTeammateState();

    MoveToTeammateState &operator=(MoveToTeammateState const &) = delete;
    MoveToTeammateState &operator=(MoveToTeammateState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !MOVETOTEAMMATESTATE_HPP_
