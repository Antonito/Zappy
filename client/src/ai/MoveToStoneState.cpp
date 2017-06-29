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
  }

  void MoveToStoneState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void MoveToStoneState::reset(Value value)
  {
  }

  Value MoveToStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
