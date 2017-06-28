#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FindStoneState::FindStoneState(std::map<BasicState, IState *> &states) : AState(states)
  {
  }

  FindStoneState::~FindStoneState()
  {
  }

  void FindStoneState::readState(std::queue<std::string> &readQueue)
  {
  }

  void FindStoneState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void FindStoneState::reset(Value value)
  {
  }

  Value FindStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
