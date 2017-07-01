#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ArrivedState::ArrivedState(
      std::map<BasicState, std::unique_ptr<IState>> &states,
      PlayerInfo &player)
      : AState(states, player)
  {
  }

  ArrivedState::~ArrivedState()
  {
  }

  void ArrivedState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Arrived[READ]State";
  }

  void ArrivedState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Arrived[WRITE]State";
  }

  void ArrivedState::reset(Value value)
  {
  }

  Value ArrivedState::getResponse() const
  {
    return (m_curValue);
  }
}
