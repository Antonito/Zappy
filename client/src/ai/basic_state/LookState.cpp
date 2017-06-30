#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LookState::LookState()
  {
  }

  LookState::~LookState()
  {
  }

  void LookState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Look[READ]BasicState";
    if (readQueue.empty())
      return;
    std::string res = readQueue.front();
    if (res == "ko\n")
      {
	nope::log::Log(Debug) << "(WARNING) Write Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
    readQueue.pop();
  }

  void LookState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Look[WRITE]BasicState";
    std::string tmp = "Look\n";
    writeQueue.push(tmp);
  }

  void LookState::reset(Value value)
  {
    m_value = value;
  }

  Value LookState::getResponse() const
  {
    return (m_value);
  }
}
