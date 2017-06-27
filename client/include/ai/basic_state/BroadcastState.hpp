#ifndef BROADCASTSTATE_HPP_
#define BROADCASTSTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class BroadcastState final : public AState
  {
  public:
    BroadcastState();
    BroadcastState(BroadcastState const &) = delete;
    BroadcastState(BroadcastState &&) = delete;
    virtual ~BroadcastState();

    BroadcastState &operator=(BroadcastState const &) = delete;
    BroadcastState &operator=(BroadcastState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

    void setMsg(std::string const &);

  private:
    Value        m_value;
    std::string &m_msg;
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !BROADCASTSTATE_HPP_
