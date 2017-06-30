#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MoveToStoneState::MoveToStoneState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  MoveToStoneState::~MoveToStoneState()
  {
  }

  void MoveToStoneState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MoveToStone[READ]State";
  }

  void MoveToStoneState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MoveToStone[WRITE]State";
  }

  void MoveToStoneState::reset(Value value)
  {
    nope::log::Log(Debug) << "MoveToStoneState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value MoveToStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
