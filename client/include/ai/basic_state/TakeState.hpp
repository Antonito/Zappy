#ifndef TAKESTATE_HPP_
#define TAKESTATE_HPP_

#include <iostream>
#include "ai/IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class TakeState final : public IState
  {
  public:
    TakeState();
    TakeState(TakeState const &) = delete;
    TakeState(TakeState &&) = delete;
    virtual ~TakeState();

    TakeState &operator=(TakeState const &) = delete;
    TakeState &operator=(TakeState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

    void setObject(std::string const &);

  private:
    Value        m_value;
    std::string m_object;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !TAKESTATE_HPP_

