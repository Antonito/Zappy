#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingPlayerState::MissingPlayerState(
      std::map<BasicState, std::unique_ptr<IState>> &states,
      PlayerInfo &player)
      : AState(states, player), m_help(false), m_goAway(false)
  {
  }

  MissingPlayerState::~MissingPlayerState()
  {
  }

  void MissingPlayerState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MissingPlayer[READ]State";
    m_states[BasicState::LOOK]->readState(readQueue);
    Value ret = m_states[BasicState::LOOK]->getResponse();
    if (ret == Value::YES)
      {
	if (m_player.getNbPlayer() >
	    static_cast<LookState *>(m_states[BasicState::LOOK])
	        ->getNbPlayer())
	  {
	    m_help = true;
	    m_states[BasicState::BROADCAST]->readState(readQueue);
	    m_canWrite = true;
	  }
	else
	  {
	    m_states[BasicState::BROADCAST]->readState(readQueue);
	    m_goAway = true;
	    m_help = false;
	  }
      }
    else
      nope::log::Log(Error) << "Look Failed !";
  }

  void MissingPlayerState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MissingPlayer[WRITE]State";
    m_states[BasicState::LOOK]->reset(Value::NO);
    m_states[BasicState::LOOK]->writeState(writeQueue);
    if (m_help == true)
      {
	static_cast<BroadcastState *>(m_states[BasicState::BROADCAST])
	    ->setMsg("EmBsTf COME " + std::to_string(m_player.getPlayerID()) + " " + std::to_string(m_player.getLevel()));
	m_states[BasicState::BROADCAST]->writeState(writeQueue);
	m_help = false;
      }
    else if (m_goAway == true)
      {
	static_cast<BroadcastState *>(m_states[BasicState::BROADCAST])
	    ->setMsg("EmBsTf GO_AWAY " + std::to_string(m_player.getPlayerID()));
	m_states[BasicState::BROADCAST]->writeState(writeQueue);
	m_goAway = false;
	m_curValue = Value::NO;
      }
    m_canWrite = false;
  }

  void MissingPlayerState::reset(Value value)
  {
    nope::log::Log(Debug) << "MissingPlayerState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_help = false;
    m_goAway = false;
    m_canWrite = true;
  }

  Value MissingPlayerState::getResponse() const
  {
    return (m_curValue);
  }
}
