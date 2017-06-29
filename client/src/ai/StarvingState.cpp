#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StarvingState::StarvingState(std::map<BasicState, IState *> &states)
      : AState(states)
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
    if (static_cast<InventoryState *>(m_states[BasicState::INVENTORY])
            ->getFood() < 8)
      {
	m_curValue = Value::YES;
      }
    else if (m_curValue == Value::YES)
      {
	m_curValue = Value::NO;
      }
    // or directly read in readQueue
  }

  void StarvingState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Starving[WRITE]State";
    // call inventory state
    m_states[BasicState::INVENTORY]->writeState(writeQueue);
    // or directly put 'Inventory\n' in writeQueue
  }

  void StarvingState::reset(Value value)
  {
    nope::log::Log(Debug) << "StarvingState reset";
  }

  Value StarvingState::getResponse() const
  {
    return (m_curValue);
  }
}
