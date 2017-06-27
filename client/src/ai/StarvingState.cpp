#include "zappy_ai_stdafx.hpp"

namespace ai
{
  StarvingState::StarvingState() : AState()
  {
  }

  StarvingState::~StarvingState()
  {
  }

  void StarvingState::readState(std::queue<std::string> &readQueue)
  {
  }

  void StarvingState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void StarvingState::reset(Value value)
  {
  }

  Value Starving::getResponse() const
  {
    return (m_curValue);
  }
}