#include "zappy_ai_stdafx.hpp"

namespace ai
{
  ArrivedState::ArrivedState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  ArrivedState::~ArrivedState()
  {
  }

  void ArrivedState::readState(std::queue<std::string> &readQueue)
  {
  }

  void ArrivedState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void ArrivedState::reset(Value value)
  {
  }

  Value ArrivedState::getResponse() const
  {
    return (m_curValue);
  }
}
