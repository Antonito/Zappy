#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LeftState::LeftState() : m_value(Value::NO)
  {
  }

  LeftState::~LeftState()
  {
  }

  void LeftState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Left[READ]BasicState";
    if (readQueue.empty())
      return;
    std::string res = readQueue.front();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Left Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void LeftState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Left[WRITE]BasicState";
    std::string tmp = "Left\n";
    writeQueue.push(tmp);
  }

  void LeftState::reset(Value value)
  {
    m_value = value;
  }

  Value LeftState::getResponse() const
  {
    return (m_value);
  }
}
