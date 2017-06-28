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
#pragma clang diagnostic ignored "-Wweak-vtable"
#endif

namespace ai
{
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

