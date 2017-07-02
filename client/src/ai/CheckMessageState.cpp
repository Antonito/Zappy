#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CheckMessageState::CheckMessageState(
      std::map<BasicState, std::unique_ptr<IState>> &states,
      PlayerInfo &player)
      : AState(states, player)
  {
  }

  CheckMessageState::~CheckMessageState()
  {
  }

  void CheckMessageState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "CheckMessage[READ]State";
    if (m_player.getMSG().empty())
      {
	return;
      }
    std::int32_t dir = 0;
    std::string  get = m_player.getMSG().front();
    m_player.getMSG().pop();
    std::stringstream ss;
    ss << get;
    std::string res;
    ss >> res;
    ss >> dir;
    ss >> res;
    ss >> res;
    if (res == "EmBsTf")
      {
	ss >> res;
	if (res == "COME")
	  {
	    std::int32_t id;
	    std::int32_t level;
	    ss >> id;
	    ss >> level;
	    if (id != m_player.getPlayerID() && id != m_player.getTargetID())
	      {
		if (level == m_player.getLevel())
		  {
		    m_player.setTargetID(id);
		    if (dir >= 0 && dir <= 8)
		      {
			m_player.setDirection(dir);
		      }
		  }
	      }
	  }
	else if (res == "GO_AWAY")
	  {
	    std::int32_t id;
	    ss >> id;
	    if (id == m_player.getTargetID())
	      {
		m_player.setTargetID(-1);
	      }
	  }
	else if (res == "END_INCANT")
	  {
	    std::int32_t id;
	    ss >> id;
	    if (id == m_player.getTargetID())
	      {
		m_player.setTargetID(-1);
	      }
	  }
	else
	  {
	    m_curValue = Value::NO;
	    nope::log::Log(Error) << "Wrong message";
	  }
      }
    else
      {
	nope::log::Log(Info) << "not a message for me";
      }
  }

  void CheckMessageState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "CheckMessage[WRITE]State";
  }

  void CheckMessageState::reset(Value value)
  {
    nope::log::Log(Debug) << "CheckMessageState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value CheckMessageState::getResponse() const
  {
    return (m_curValue);
  }
}
