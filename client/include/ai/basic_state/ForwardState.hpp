#ifndef FORWARDSTATE_HPP_
#define FORWARDSTATE_HPP_

#include <iostream>
#include "ai/IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class ForwardState final : public IState
  {
  public:
    ForwardState();
    ForwardState(ForwardState const &) = delete;
    ForwardState(ForwardState &&) = delete;
    virtual ~ForwardState();

    ForwardState &operator=(ForwardState const &) = delete;
    ForwardState &operator=(ForwardState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    Value m_value;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FORWARDSTATE_HPP_

