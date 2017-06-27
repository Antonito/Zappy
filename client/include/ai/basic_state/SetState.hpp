#ifndef SETSTATE_HPP_
#define SETSTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class SetState final : public IState
  {
  public:
    SetState();
    SetState(SetState const &) = delete;
    SetState(SetState &&) = delete;
    virtual ~SetState();

    SetState &operator=(SetState const &) = delete;
    SetState &operator=(SetState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

    void setObject(std::string const &);

  private:
    Value        m_value;
    std::string &m_object;
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !SETSTATE_HPP_
