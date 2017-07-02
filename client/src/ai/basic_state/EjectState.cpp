#include "zappy_ai_stdafx.hpp"

namespace ai
{
  EjectState::EjectState() : m_value(Value::NO)
  {
  }

  EjectState::~EjectState()
  {
  }

  void EjectState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Eject[READ]BasicState";
    if (readQueue.empty())
    {
      m_value = Value::NO;
      return;
    }
    std::string res = readQueue.front();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Eject Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void EjectState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Eject[WRITE]BasicState";
    std::string tmp = "Eject\n";
    writeQueue.push(tmp);
  }

  void EjectState::reset(Value value)
  {
    m_value = value;
  }

  Value EjectState::getResponse() const
  {
    return (m_value);
  }
}
