#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingStoneState::MissingStoneState(std::map<BasicState, IState *> &states) : AState(states)
  {
  }

  MissingStoneState::~MissingStoneState()
  {
  }

  void MissingStoneState::readState(std::queue<std::string> &readQueue)
  {
  }

  void MissingStoneState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void MissingStoneState::reset(Value value)
  {
  }

  Value MissingStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
