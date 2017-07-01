#include "zappy_ai_stdafx.hpp"

namespace ai
{
  TakeState::TakeState() : m_value(Value::NO), m_object("")
  {
  }

  TakeState::~TakeState()
  {
  }

  void TakeState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Take[READ]BasicState";
    if (readQueue.empty())
      return;
    std::string res = readQueue.front();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Take Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void TakeState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Take[WRITE]BasicState";
    std::string tmp = "Take " + m_object + "\n";
    writeQueue.push(tmp);
  }

  void TakeState::reset(Value value)
  {
    m_value = value;
  }

  Value TakeState::getResponse() const
  {
    return (m_value);
  }

  void TakeState::setObject(std::string const &str)
  {
    m_object = str;
  }
}
