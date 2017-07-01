#include "zappy_ai_stdafx.hpp"

namespace ai
{
  TrollState::TrollState(std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  TrollState::~TrollState()
  {
  }

  void TrollState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Troll[READ]State";
  }

  void TrollState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Troll[WRITE]State";
  }

  void TrollState::reset(Value value)
  {
    nope::log::Log(Debug) << "TrollState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value TrollState::getResponse() const
  {
    return (m_curValue);
  }
}
