#include "zappy_ai_stdafx.hpp"

namespace ai
{
  TrollState::TrollState(std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
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
