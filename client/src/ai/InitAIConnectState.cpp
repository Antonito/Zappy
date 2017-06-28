#include "zappy_ai_stdafx.hpp"

namespace ai
{
  InitAIConnectState::InitAIConnectState() : AState(), m_changeState(false)
  {
  }

  InitAIConnectState(InitAIConnectState const &that)
    : AState(that), m_changeState(that.m_changeState)
  {
  }

  InitAIConnectState(InitAIConnectState &&that)
  : AState(that), m_changeState(std::move(that.m_changeState))
  {
  }

  InitAIConnectState::~InitAIConnectState()
  {
  }

  void InitAIConnectState::readState(std::queue<std::string> &readQueue)
  {
    std::string tmp = readQueue.front();
    readQueue.pop();
    if (tmp == "Welcome\n")
    {
      nope::log::Log(Debug) << "got server's Welcome";
    }
    else
    {
      nope::log::Log(Debug) << "might got the map's size, time to play";
    }
    if (m_changeState == true)
    {
      m_curValue = Value::YES;
    }
    m_changeState = !m_changeState;
  }

  void InitAIConnectState::writeState(std::queue<std::string> &writeQueue)
  {
    //TODO : dynamic team name
    writeQueue.push("Team1");
  }

  void InitAIConnectState::reset(Value value)
  {
  }

  Value InitAIConnectState::getResponse() const
  {
    return (m_curValue);
  }
}
