#ifndef CHECKMESSAGESTATE_HPP_
#define CHECKMESSAGESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class CheckMessageState final : public AState
  {
  public:
    CheckMessageState();
    CheckMessageState(CheckMessageState const &) = delete;
    CheckMessageState(CheckMessageState &&) = delete;
    virtual ~CheckMessageState();

    CheckMessageState &operator=(CheckMessageState const &) = delete;
    CheckMessageState &operator=(CheckMessageState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  }

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !CHECKMESSAGESTATE_HPP_