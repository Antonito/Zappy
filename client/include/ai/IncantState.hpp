#ifndef INCANTSTATE_HPP_
#define INCANTSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class IncantState final : public AState
  {
  public:
    IncantState();
    IncantState(IncantState const &) = delete;
    IncantState(IncantState &&) = delete;
    virtual ~IncantState();

    IncantState &operator=(IncantState const &) = delete;
    IncantState &operator=(IncantState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !INCANTSTATE_HPP_

