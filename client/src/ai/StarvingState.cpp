#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StarvingState::StarvingState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
    nope::log::Log(Debug) << "Starving State init";
  }

  StarvingState::~StarvingState()
  {
  }

  void StarvingState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Starving[READ]State";
    // call inventory state
    m_states[BasicState::INVENTORY]->readState(readQueue);
    std::int32_t food =
        static_cast<InventoryState *>(m_states[BasicState::INVENTORY])
            ->getFood();
    nope::log::Log(Debug) << food << " food unit";
    if (food < NB_FOOD_NORMAL)
      {
	m_curValue = Value::YES;
      }
    else if (food < NB_FOOD_MIN)
    {
      m_curValue = Value::YES;
    }
    else if (m_retValue == Value::YES)
      {
	m_curValue = Value::NO;
      }
    else
      {
	m_curValue = m_retValue;
      }
    // or directly read in readQueue
  }

  void StarvingState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Starving[WRITE]State";
    nope::log::Log(Debug) << "ADDR " << m_states[BasicState::INVENTORY];
    m_states[BasicState::INVENTORY]->writeState(writeQueue);
    m_canWrite = false;
  }

  void StarvingState::reset(Value value)
  {
    nope::log::Log(Debug) << "StarvingState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    nope::log::Log(Debug) << "m_curValue = " << m_curValue;
    m_canWrite = true;
  }

  Value StarvingState::getResponse() const
  {
    return (m_curValue);
  }
}
