#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MoveToTeammateState::MoveToTeammateState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  MoveToTeammateState::~MoveToTeammateState()
  {
  }

  void MoveToTeammateState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MoveToTeammate[READ]State";
  }

  void MoveToTeammateState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MoveToTeammate[WRITE]State";
  }

  void MoveToTeammateState::reset(Value value)
  {
    nope::log::Log(Debug) << "MoveToTeammateState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value MoveToTeammateState::getResponse() const
  {
    return (m_curValue);
  }
}
