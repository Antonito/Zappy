#include "zappy_ai_stdafx.hpp"

namespace ai
{
  AState::AState() : m_states(), m_curState(), m_curValue()
  {
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