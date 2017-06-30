#include "zappy_ai_stdafx.hpp"

namespace ai
{
  BroadcastState::BroadcastState()
  {
  }

  BroadcastState::~BroadcastState()
  {
  }

  void BroadcastState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Broadcast[READ]BasicState";
    m_value = Value::YES;
  }

  void BroadcastState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Broadcast[WRITE]BasicState";
  }

  void BroadcastState::reset(Value value)
  {
    m_value = value;
  }

  Value BroadcastState::getResponse() const
  {
    return (m_value);
  }

  void BroadcastState::setMsg(std::string const &str)
  {
  }
}
