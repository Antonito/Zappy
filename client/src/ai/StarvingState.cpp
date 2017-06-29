#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StarvingState::StarvingState() : AState()
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
    m_states[BasicState::Inventory].readState();
    if (m_states[BasicState::Inventory].getFood() < 8)
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
    m_states[BasicState::Inventory].writeState();
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
