#ifndef RIGHTSTATE_HPP_
#define RIGHTSTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class RightState final : public IState
  {
  public:
    RightState();
    RightState(RightState const &) = delete;
    RightState(RightState &&) = delete;
    virtual ~RightState();

    RightState &operator=(RightState const &) = delete;
    RightState &operator=(RightState &&) = delete;

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

#endif // !RIGHTSTATE_HPP_
