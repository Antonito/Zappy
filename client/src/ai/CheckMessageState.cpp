#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CheckMessageState::CheckMessageState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  CheckMessageState::~CheckMessageState()
  {
  }

  void CheckMessageState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "CheckMessage[READ]State";
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
