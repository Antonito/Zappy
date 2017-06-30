#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingPlayerState::MissingPlayerState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  MissingPlayerState::~MissingPlayerState()
  {
  }

  void MissingPlayerState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MissingPlayer[READ]State";
  }

  void MissingPlayerState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MissingPlayer[WRITE]State";
  }

  void MissingPlayerState::reset(Value value)
  {
    nope::log::Log(Debug) << "MissingPlayerState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value MissingPlayerState::getResponse() const
  {
    return (m_curValue);
  }
}
