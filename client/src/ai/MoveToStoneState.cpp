#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MoveToStoneState::MoveToStoneState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  MoveToStoneState::~MoveToStoneState()
  {
  }

  void MoveToStoneState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MoveToStone[READ]State";
    if (m_first)
      {
	for (std::int32_t y = 0; y < m_direction.second; ++y)
	  {
	    m_states[BasicState::FORWARD]->readState(readQueue);
	  }
	m_first = false;
	m_second = true;
	m_curValue = Value::LOOP;
      }
    else if (m_second)
      {
	if (m_direction.first > 0)
	  {
	    m_states[BasicState::RIGHT]->readState(readQueue);
	  }
	else
	  {
	    m_states[BasicState::LEFT]->readState(readQueue);
	  }
	for (std::int32_t x = 0; x < m_direction.first; ++x)
	  {
	    m_states[BasicState::FORWARD]->readState(readQueue);
	  }
	m_first = true;
	m_second = false;
	m_curValue = Value::YES;
      }
  }

  void MoveToStoneState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MoveToStone[WRITE]State";
    if (m_first)
      {
	for (std::int32_t y = 0; y < m_direction.second; ++y)
	  {
	    m_states[BasicState::FORWARD]->writeState(writeQueue);
	  }
      }
    if (m_second)
      {
	if (m_direction.first > 0)
	  {
	    m_states[BasicState::RIGHT]->writeState(writeQueue);
	  }
	else
	  {
	    m_states[BasicState::LEFT]->writeState(writeQueue);
	  }
	for (std::int32_t x = 0; x < m_direction.first; ++x)
	  {
	    m_states[BasicState::FORWARD]->writeState(writeQueue);
	  }
      }
    m_canWrite = false;
  }

  void MoveToStoneState::reset(Value value)
  {
    nope::log::Log(Debug) << "MoveToStoneState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    std::int32_t pos = static_cast<LookState *>(m_states[BasicState::LOOK])->findStone();
    m_direction = static_cast<LookState *>(m_states[BasicState::LOOK])->getDirection(pos);
    m_first = true;
    m_second = false;
    m_canWrite = true;
  }

  Value MoveToStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
