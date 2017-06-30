#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StoneOnCaseState::StoneOnCaseState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  StoneOnCaseState::~StoneOnCaseState()
  {
  }

  void StoneOnCaseState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "StoneOnCase[READ]State";
  }

  void StoneOnCaseState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "StoneOnCase[WRITE]State";
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
