#include "zappy_ai_stdafx.hpp"

namespace ai
{
  AState::AState(std::map<BasicState, std::unique_ptr<IState>> &states)
      : m_curState(), m_curValue(Value::LOOP)
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
        m_curValue(that.m_curValue)
  {
  }

  AState::AState(AState &&that)
      : m_states(that.m_states), m_curState(std::move(that.m_curState)),
        m_curValue(std::move(that.m_curValue))
  {
  }

  AState &AState::operator=(AState const &that)
  {
    if (this == &that)
      return (*this);
    m_states = that.m_states;
    m_curState = that.m_curState;
    m_curValue = that.m_curValue;
    return (*this);
  }

  AState &AState::operator=(AState &&that)
  {
    if (this == &that)
      return (*this);
    m_states = std::move(that.m_states);
    m_curState = std::move(that.m_curState);
    m_curValue = std::move(that.m_curValue);
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
