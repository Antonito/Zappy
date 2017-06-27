#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CollectStoneState::CollectStoneState() : AState()
  {
  }

  CollectStoneState::~CollectStoneState()
  {
  }

  void CollectStoneState::readState(std::queue<std::string> &readQueue)
  {
  }

  void CollectStoneState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void CollectStoneState::reset(Value value)
  {
  }

  Value CollectStoneState::getResponse() const
  {
    return (m_curValue);
  }
}