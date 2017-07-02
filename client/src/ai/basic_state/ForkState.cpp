#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ForkState::ForkState() : m_value(Value::NO)
  {
  }

  ForkState::~ForkState()
  {
  }

  void ForkState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Fork[READ]BasicState";
    if (readQueue.empty())
    {
      m_value = Value::NO;
      return;
    }
    std::string res = readQueue.front();
    readQueue.pop();
    if (res != "ok\n")
      {
	nope::log::Log(Debug) << "(WARNING) Fork Failed !";
        m_value = Value::NO;
      }
    m_value = Value::YES;
  }

  void ForkState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Fork[WRITE]BasicState";
    std::string tmp = "Fork\n";
    writeQueue.push(tmp);
  }

  void ForkState::reset(Value value)
  {
    m_value = value;
  }

  Value ForkState::getResponse() const
  {
    return (m_value);
  }
}
