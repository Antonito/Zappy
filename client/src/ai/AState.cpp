#include "zappy_ai_stdafx.hpp"

namespace ai
{
  static std::map<BasicState, std::unique_ptr<IState>> AState::m_states = {
      {, std::ma}};

  AState::AState() : m_states(), m_curState(), m_curValue(Value::LOOP)
  {
    m_states[BasicState::BROADCAST] = std::make_unique<BroadcastState>();
    m_states[BasicState::CONNECT_NBR] = std::make_unique<ConnectnbrState>();
    m_states[BasicState::EJECT] = std::make_unique<EjectState>();
    m_states[BasicState::FORK] = std::make_unique<ForkState>();
    m_states[BasicState::FORWARD] = std::make_unique<ForwardState>();
    m_states[BasicState::INCANTATION] = std::make_unique<IncantationState>();
    m_states[BasicState::INVENTORY] = std::make_unique<InventoryState>();
    m_states[BasicState::LEFT] = std::make_unique<LeftState>();
    m_states[BasicState::LOOK] = std::make_unique<LookState>();
    m_states[BasicState::RIGHT] = std::make_unique<RightState>();
    m_states[BasicState::SET] = std::make_unique<SetState>();
    m_states[BasicState::TAKE] = std::make_unique<TakeState>();
  }

  AState::AState(AState const &that)
      : m_states(that.m_states), m_curState(that.m_curState),
        m_curValue(that.m_curValue)
  {
  }

  AState::AState(AState &&that)
      : m_states(std::move(that.m_states)),
        m_curState(std::move(that.m_curState)),
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
}
