#ifndef FINDSTONESTATE_HPP_
#define FINDSTONESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class FindStoneState final : public AState
  {
  public:
    FindStoneState(std::map<BasicState, IState *> &states);
    FindStoneState(FindStoneState const &) = delete;
    FindStoneState(FindStoneState &&) = delete;
    virtual ~FindStoneState();

    FindStoneState &operator=(FindStoneState const &) = delete;
    FindStoneState &operator=(FindStoneState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FINDSTONESTATE_HPP_

