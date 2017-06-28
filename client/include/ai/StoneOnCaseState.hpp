#ifndef STONEONCASESTATE_HPP_
#define STONEONCASESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class StoneOnCaseState final : public AState
  {
  public:
    StoneOnCaseState(std::map<BasicState, IState *> &states);
    StoneOnCaseState(StoneOnCaseState const &) = delete;
    StoneOnCaseState(StoneOnCaseState &&) = delete;
    virtual ~StoneOnCaseState();

    StoneOnCaseState &operator=(StoneOnCaseState const &) = delete;
    StoneOnCaseState &operator=(StoneOnCaseState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !STONEONCASESTATE_HPP_

