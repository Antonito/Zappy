#include "zappy_ai_stdafx.hpp"

namespace ai
{
  SetState::SetState() : m_value(Value::NO), m_object("")
  {
  }

  SetState::~SetState()
  {
  }

  void SetState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Set[READ]BasicState";
    if (readQueue.empty())
      return;
    std::string res = readQueue.front();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Set Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void SetState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Set[WRITE]BasicState";
    std::string tmp = "Set " + m_object + "\n";
    writeQueue.push(tmp);
  }

  void SetState::reset(Value value)
  {
    m_value = value;
  }

  Value SetState::getResponse() const
  {
    return (m_value);
  }

  void SetState::setObject(std::string const &str)
  {
    m_object = str;
  }
}
