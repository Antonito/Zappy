#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MoveToTeammateState::MoveToTeammateState(std::map<BasicState, IState *> &states) : AState(states)
  {
  }

  MoveToTeammateState::~MoveToTeammateState()
  {
  }

  void MoveToTeammateState::readState(std::queue<std::string> &readQueue)
  {
  }

  void MoveToTeammateState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void MoveToTeammateState::reset(Value value)
  {
  }

  Value MoveToTeammateState::getResponse() const
  {
    return (m_curValue);
  }
}
