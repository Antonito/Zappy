#ifndef INITAICONNECT_HPP_
#define INITAICONNECT_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class InitAIConnectState final : public AState
  {
  public:
    InitAIConnectState(std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player);
    InitAIConnectState(InitAIConnectState const &);
    InitAIConnectState(InitAIConnectState &&);
    virtual ~InitAIConnectState();

    InitAIConnectState &operator=(InitAIConnectState const &) = delete;
    InitAIConnectState &operator=(InitAIConnectState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    bool m_changeState;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !INITAICONNECT_HPP_
