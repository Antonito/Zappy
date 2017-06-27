#ifndef FORKSTATE_HPP_
#define FORKSTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class ForkState final : public IState
  {
  public:
    ForkState();
    ForkState(ForkState const &) = delete;
    ForkState(ForkState &&) = delete;
    virtual ~ForkState();

    ForkState &operator=(ForkState const &) = delete;
    ForkState &operator=(ForkState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    Value m_value;
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FORKSTATE_HPP_
