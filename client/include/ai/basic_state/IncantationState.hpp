#ifndef INCANTATIONSTATE_HPP_
#define INCANTATIONSTATE_HPP_

#include <iostream>
#include "ai/IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class IncantationState final : public IState
  {
  public:
    IncantationState();
    IncantationState(IncantationState const &) = delete;
    IncantationState(IncantationState &&) = delete;
    virtual ~IncantationState();

    IncantationState &operator=(IncantationState const &) = delete;
    IncantationState &operator=(IncantationState &&) = delete;

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

#endif // !INCANTATIONSTATE_HPP_

