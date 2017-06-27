#ifndef EJECTSTATE_HPP_
#define EJECTSTATE_HPP_

#include <iostream>
#include "ai/IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class EjectState final : public IState
  {
  public:
    EjectState();
    EjectState(EjectState const &) = delete;
    EjectState(EjectState &&) = delete;
    virtual ~EjectState();

    EjectState &operator=(EjectState const &) = delete;
    EjectState &operator=(EjectState &&) = delete;

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

#endif // !EJECTSTATE_HPP_

