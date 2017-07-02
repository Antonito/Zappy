#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StoneOnCaseState::StoneOnCaseState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
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
    
    std::array<std::int32_t, 6> diff = m_player.missingStone(static_cast<InventoryState *>(m_states[BasicState::INVENTORY])->getInventory());

    for (std::int32_t i = 0; i < 6; ++i)
    {
      if (diff[static_cast<std::size_t>(i)] > 0)
      {
        static_cast<LookState *>(m_states[BasicState::LOOK])->setStone(m_player.getStoneName(i));
        break;
      }
    }

    Value ret = m_states[BasicState::LOOK]->getResponse();
    if (ret == Value::YES)
      {
	if (static_cast<LookState *>(m_states[BasicState::LOOK])->findStone() == 0)
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
