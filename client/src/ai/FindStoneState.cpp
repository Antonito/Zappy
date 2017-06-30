#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FindStoneState::FindStoneState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states), m_lookAround(0), m_goForward(false)
  {
  }

  FindStoneState::~FindStoneState()
  {
  }

  void FindStoneState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "FindStone[READ]State";
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
	if (m_states[BasicState::LOOK]->findStone() == -1)
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

  void FindStoneState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "FindStone[WRITE]State";
    if (m_lookAround > 0)
      {
	m_states[BasicState::RIGHT]->writeState(writeQueue);
      }
    if (m_goForward == true)
      {
	m_states[BasicState::FORWARD]->writeState(writeQueue);
      }
    m_states[BasicState::LOOK]->writeState(writeQueue);
    m_canWrite = false;
  }

  void FindStoneState::reset(Value value)
  {
    nope::log::Log(Debug) << "FindFoodState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
    m_lookAround = 0;
    m_goForward = false;
  }

  Value FindStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
