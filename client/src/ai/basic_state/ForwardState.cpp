#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ForwardState::ForwardState() : m_value(Value::NO)
  {
  }

  ForwardState::~ForwardState()
  {
  }

  void ForwardState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Forward[READ]BasicState";
    if (readQueue.empty())
      return;
    std::string res = readQueue.front();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Forward Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void ForwardState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Forward[WRITE]BasicState";
    std::string tmp = "Forward\n";
    writeQueue.push(tmp);
  }

  void ForwardState::reset(Value value)
  {
    m_value = value;
  }

  Value ForwardState::getResponse() const
  {
    return (m_value);
  }
}
