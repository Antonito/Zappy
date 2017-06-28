#include "zappy_ai_stdafx.hpp"

namespace ai
{
  InitAIConnectState::InitAIConnectState() : AState()
  {
  }

  InitAIConnectState::~InitAIConnectState()
  {
  }

  void InitAIConnectState::readState(std::queue<std::string> &readQueue)
  {
  }

  void InitAIConnectState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void InitAIConnectState::reset(Value value)
  {
  }

  Value InitAIConnectState::getResponse() const
  {
    return (m_curValue);
  }
}
