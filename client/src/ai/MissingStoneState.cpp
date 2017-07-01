#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingStoneState::MissingStoneState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  MissingStoneState::~MissingStoneState()
  {
  }

  void MissingStoneState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MissingStone[READ]State";
  }

  void MissingStoneState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MissingStone[WRITE]State";
  }

  void MissingStoneState::reset(Value value)
  {
    nope::log::Log(Debug) << "MissingStoneState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value MissingStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
