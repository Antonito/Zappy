#include "zappy_ai_stdafx.hpp"

namespace ai
{
  IncantState::IncantState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  IncantState::~IncantState()
  {
  }

  void IncantState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Incant[READ]State";
    m_states[BasicState::INCANTATION]->readState(readQueue);
    Value ret = m_states[BasicState::INCANTATION]->getResponse();
    if (ret == Value::YES)
      {
	m_curValue = Value::YES;
	// Update level
      }
    else
      m_curValue = Value::NO;
  }

  void IncantState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Incant[WRITE]State";
    m_states[BasicState::INCANTATION]->writeState(writeQueue);
    m_canWrite = false;
  }

  void IncantState::reset(Value value)
  {
    nope::log::Log(Debug) << "IncantState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value IncantState::getResponse() const
  {
    return (m_curValue);
  }
}
