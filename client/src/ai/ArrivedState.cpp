#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ArrivedState::ArrivedState(
      std::map<BasicState, std::unique_ptr<IState>> &states,
      PlayerInfo &player)
      : AState(states, player), m_counter(0)
  {
  }

  ArrivedState::~ArrivedState()
  {
  }

  void ArrivedState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Arrived[READ]State";
    if (m_player.getDirection() == 0)
    {
      ++m_counter;
      if (m_counter > 4)
      {
        m_curValue = Value::READY;
        m_counter = 0;
      }
      else
      {
        m_curValue = Value::YES;
      }
    }
    else
    {
      m_curValue = Value::NO;
    }
  }

  void ArrivedState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Arrived[WRITE]State";
  }

  void ArrivedState::reset(Value value)
  {
  }

  Value ArrivedState::getResponse() const
  {
    return (m_curValue);
  }
}
