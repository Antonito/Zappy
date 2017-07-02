#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingStoneState::MissingStoneState(
      std::map<BasicState, std::unique_ptr<IState>> &states,
      PlayerInfo &player)
      : AState(states, player)
  {
  }

  MissingStoneState::~MissingStoneState()
  {
  }

  void MissingStoneState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MissingStone[READ]State";
    m_states[BasicState::INVENTORY]->readState(readQueue);
    Value ret = m_states[BasicState::INVENTORY]->getResponse();
    if (ret == Value::YES)
      {
	std::array<std::int32_t, 6> inventory =
	    static_cast<InventoryState *>(m_states[BasicState::INVENTORY])
	        ->getInventory();
	if (enoughStone(m_player.missingStone(inventory)))
	  {
	    m_curValue = Value::NO;
	  }
	else
	  m_curValue = Value::YES;
      }
    nope::log::Log(Error) << "Inventory Failed";
  }

  void MissingStoneState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MissingStone[WRITE]State";
    m_states[BasicState::INVENTORY]->reset(Value::NO);
    m_states[BasicState::INVENTORY]->writeState(writeQueue);
    m_canWrite = false;
  }

  void MissingStoneState::reset(Value value)
  {
    nope::log::Log(Debug) << "MissingStoneState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  bool MissingStoneState::enoughStone(
      std::array<std::int32_t, 6> const stoneArray) const
  {
    for (std::size_t i = 0; i < 6; i++)
      {
	if (stoneArray[i] > 0)
	  {
	    return (false);
	  }
      }
    return (true);
  }

  Value MissingStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
