#include "zappy_ai_stdafx.hpp"

namespace ai
{
  IncantationState::IncantationState() : m_value(Value::NO)
  {
  }

  IncantationState::~IncantationState()
  {
  }

  void IncantationState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Incantation[READ]BasicState";
    if (readQueue.empty())
    {
      m_value = Value::NO;
      return;
    }
    std::string res = readQueue.front();
    readQueue.pop();
    if (res == "ko\n")
      {
	nope::log::Log(Debug) << "(WARNING) Incantation Failed !";
	m_value = Value::NO;
      }
    m_value = Value::YES;
  }

  void IncantationState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Incantation[WRITE]BasicState";
    std::string tmp = "Incantation\n";
    writeQueue.push(tmp);
  }

  void IncantationState::reset(Value value)
  {
    m_value = value;
  }

  Value IncantationState::getResponse() const
  {
    return (m_value);
  }
}
