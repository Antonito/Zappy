#ifndef LEFTSTATE_HPP_
#define LEFTSTATE_HPP_

#include <iostream>
#include "ai/IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class LeftState final : public IState
  {
  public:
    LeftState();
    LeftState(LeftState const &) = delete;
    LeftState(LeftState &&) = delete;
    virtual ~LeftState();

    LeftState &operator=(LeftState const &) = delete;
    LeftState &operator=(LeftState &&) = delete;

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

#endif // !LEFTSTATE_HPP_

