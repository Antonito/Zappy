#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StoneOnCaseState::StoneOnCaseState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  StoneOnCaseState::~StoneOnCaseState()
  {
  }

  void StoneOnCaseState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "StoneOnCase[READ]State";
    m_states[BasicState::LOOK]->readState(readQueue);
    // TODO: set the stone to find
    Value ret = m_states[BasicState::LOOK]->getResponse();
    if (ret == Value::YES)
      {
	if (m_states[BasicState::LOOK]->findStone() == 0)
	  {
	    m_curValue = Value::YES;
	  }
	else
	  {
	    m_curValue = Value::NO;
	  }
      }
  }

  void StoneOnCaseState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "StoneOnCase[WRITE]State";
    m_states[BasicState::LOOK]->reset(Value::NO);
    m_states[BasicState::LOOK]->writeState(writeQueue);
    m_canWrite = false;
  }

  void StoneOnCaseState::reset(Value value)
  {
    nope::log::Log(Debug) << "StoneOnCaseState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value StoneOnCaseState::getResponse() const
  {
    return (m_curValue);
  }
}
