#ifndef ASTATE_HPP_
#define ASTATE_HPP_

#include <iostream>
#include "IState.hpp"
#include "PlayerInfo.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#pragma clang diagnostic ignored "-Wweak-vtables"
#endif

namespace ai
{
  enum BasicState : std::int8_t
  {
    BROADCAST,
    CONNECT_NBR,
    EJECT,
    FORK,
    FORWARD,
    INCANTATION,
    INVENTORY,
    LEFT,
    LOOK,
    RIGHT,
    SET,
    TAKE,
  };

  class AState : public IState
  {
  public:
    AState(std::map<BasicState, std::unique_ptr<IState>> &states,
           PlayerInfo &player);
    AState(AState const &);
    AState(AState &&) = delete;
    virtual ~AState();

    AState &operator=(AState const &);
    AState &operator=(AState &&) = delete;

    bool canWrite() const;
    void setWrite(bool set);

  protected:
    std::map<BasicState, IState *> m_states;
    State       m_curState;
    Value       m_curValue;
    Value       m_retValue;
    bool        m_canWrite;
    PlayerInfo &m_player;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !ASTATE_HPP_
