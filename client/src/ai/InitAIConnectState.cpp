#include "zappy_ai_stdafx.hpp"

namespace ai
{
  InitAIConnectState::InitAIConnectState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states), m_changeState(false)
  {
  }

  InitAIConnectState::InitAIConnectState(InitAIConnectState const &that)
      : AState(that), m_changeState(that.m_changeState)
  {
  }

  InitAIConnectState::InitAIConnectState(InitAIConnectState &&that)
      : AState(that), m_changeState(std::move(that.m_changeState))
  {
  }

  InitAIConnectState::~InitAIConnectState()
  {
  }

  void InitAIConnectState::readState(std::queue<std::string> &readQueue)
  {
    std::string tmp = readQueue.front();
    std::cout << "!" << tmp << "!" << std::endl;
    readQueue.pop();
    if (tmp == "WELCOME\n")
      {
	nope::log::Log(Debug) << "got server's Welcome";
	m_canWrite = true;
      }
    else
      {
	nope::log::Log(Debug) << "might got the map's size, time to play";
      }
    if (m_changeState == true)
      {
	m_curValue = Value::YES;
	nope::log::Log(Debug) << "Should change state";
      }
    m_changeState = !m_changeState;
  }

  void InitAIConnectState::writeState(std::queue<std::string> &writeQueue)
  {
    // TODO : dynamic team name
    nope::log::Log(Debug) << "pushing 'Team1' into writeQueue";
    writeQueue.push("Team1\n");
    m_canWrite = false;
  }

  void InitAIConnectState::reset(Value value)
  {
  }

  Value InitAIConnectState::getResponse() const
  {
    return (m_curValue);
  }
}
