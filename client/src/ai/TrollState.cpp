#include "zappy_ai_stdafx.hpp"

namespace ai
{
  TrollState::TrollState() : AState()
  {
  }

  TrollState::~TrollState()
  {
  }

  void TrollState::readState(std::queue<std::string> &readQueue)
  {
  }

  void TrollState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void TrollState::reset(Value value)
  {
  }

  Value TrollState::getResponse() const
  {
    return (m_curValue);
  }
}