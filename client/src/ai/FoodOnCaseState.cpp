#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FoodOnCaseState::FoodOnCaseState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  FoodOnCaseState::~FoodOnCaseState()
  {
  }

  void FoodOnCaseState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "FoodOnCase[READ]State";
    m_states[BasicState::LOOK]->readState(readQueue);
    Value ret = m_states[BasicState::LOOK]->getResponse();
    if (ret == Value::YES)
      {
	if (static_cast<LookState *>(m_states[BasicState::LOOK])->findFood() == 0)
	  {
	    m_curValue = Value::YES;
	  }
	else
	  {
	    m_curValue = Value::NO;
	  }
      }
  }

  void FoodOnCaseState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "FoodOnCase[WRITE]State";
    m_states[BasicState::LOOK]->reset(Value::NO);
    m_states[BasicState::LOOK]->writeState(writeQueue);
    m_canWrite = false;
  }

  void FoodOnCaseState::reset(Value value)
  {
    nope::log::Log(Debug) << "FoodOnCaseState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value FoodOnCaseState::getResponse() const
  {
    return (m_curValue);
  }
}
