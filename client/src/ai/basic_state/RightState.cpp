#include "zappy_ai_stdafx.hpp"

namespace ai
{
  RightState::RightState() : m_value(Value::NO)
  {
  }

  RightState::~RightState()
  {
  }

  void RightState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Right[READ]BasicState";
    if (readQueue.empty())
    {
      m_value = Value::NO;
      return;
    }
    std::string res = readQueue.front();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Right Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void RightState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Right[WRITE]BasicState";
    std::string tmp = "Right\n";
    writeQueue.push(tmp);
  }

  void RightState::reset(Value value)
  {
    m_value = value;
  }

  Value RightState::getResponse() const
  {
    return (m_value);
  }
}
