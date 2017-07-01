#include "zappy_ai_stdafx.hpp"

namespace ai
{
  AState::AState(std::map<BasicState, std::unique_ptr<IState>> &states,
                 PlayerInfo &player)
      : m_curState(), m_curValue(Value::LOOP), m_retValue(Value::YES),
        m_player(player)
  {
    m_canWrite = false;
    m_states[BasicState::BROADCAST] = states[BasicState::BROADCAST].get();
    m_states[BasicState::CONNECT_NBR] = states[BasicState::CONNECT_NBR].get();
    m_states[BasicState::EJECT] = states[BasicState::EJECT].get();
    m_states[BasicState::FORK] = states[BasicState::FORK].get();
    m_states[BasicState::FORWARD] = states[BasicState::FORWARD].get();
    m_states[BasicState::INCANTATION] = states[BasicState::INCANTATION].get();
    m_states[BasicState::INVENTORY] = states[BasicState::INVENTORY].get();
    m_states[BasicState::LEFT] = states[BasicState::LEFT].get();
    m_states[BasicState::LOOK] = states[BasicState::LOOK].get();
    m_states[BasicState::RIGHT] = states[BasicState::RIGHT].get();
    m_states[BasicState::SET] = states[BasicState::SET].get();
    m_states[BasicState::TAKE] = states[BasicState::TAKE].get();
  }

  AState::AState(AState const &that)
      : m_states(that.m_states), m_curState(that.m_curState),
        m_curValue(that.m_curValue), m_player(that.m_player)
  {
  }

  AState &AState::operator=(AState const &that)
  {
    if (this == &that)
      return (*this);
    m_states = that.m_states;
    m_curState = that.m_curState;
    m_curValue = that.m_curValue;
    m_player = that.m_player;
    return (*this);
  }

  AState::~AState()
  {
  }

  bool AState::canWrite() const
  {
    return (m_canWrite);
  }

  void AState::setWrite(bool set)
  {
    m_canWrite = set;
  }
}
