#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MissingPlayerState::MissingPlayerState() : AState()
  {
  }

  MissingPlayerState::~MissingPlayerState()
  {
  }

  void MissingPlayerState::readState(std::queue<std::string> &readQueue)
  {
  }

  void MissingPlayerState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void MissingPlayerState::reset(Value value)
  {
  }

  Value MissingPlayerState::getResponse() const
  {
    return (m_curValue);
  }
}