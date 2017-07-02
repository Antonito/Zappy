#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FindFoodState::FindFoodState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player), m_lookAround(0), m_goForward(false)
  {
  }

  FindFoodState::~FindFoodState()
  {
  }

  void FindFoodState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "FindFood[READ]State";
    if (m_lookAround > 0)
      {
	m_states[BasicState::RIGHT]->readState(readQueue);
	if (m_lookAround == 4)
	  {
	    m_lookAround = 0;
	    m_goForward = true;
	  }
      }
    if (m_goForward == true)
      {
	m_states[BasicState::FORWARD]->readState(readQueue);
	m_goForward = false;
      }
    m_states[BasicState::LOOK]->readState(readQueue);
    Value ret = m_states[BasicState::LOOK]->getResponse();
    if (ret == Value::YES)
      {
	if (static_cast<LookState *>(m_states[BasicState::LOOK])->findFood() == -1)
	  {
	    m_curValue = Value::LOOP;
	    m_canWrite = true;
	    m_lookAround++;
	  }
	else
	  {
	    m_curValue = Value::YES;
	  }
      }
  }

  void FindFoodState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "FindFood[WRITE]State";
    if (m_lookAround > 0)
      {
	m_states[BasicState::RIGHT]->writeState(writeQueue);
      }
    if (m_goForward == true)
      {
	m_states[BasicState::FORWARD]->writeState(writeQueue);
      }
    m_states[BasicState::LOOK]->reset(Value::NO);
    m_states[BasicState::LOOK]->writeState(writeQueue);
    m_canWrite = false;
  }

  void FindFoodState::reset(Value value)
  {
    nope::log::Log(Debug) << "FindFoodState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
    m_lookAround = 0;
    m_goForward = false;
  }

  Value FindFoodState::getResponse() const
  {
    return (m_curValue);
  }
}
