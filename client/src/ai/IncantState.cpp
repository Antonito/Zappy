#include "zappy_ai_stdafx.hpp"

namespace ai
{
  IncantState::IncantState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  IncantState::~IncantState()
  {
  }

  void IncantState::readState(std::queue<std::string> &readQueue)
  {
  }

  void IncantState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void IncantState::reset(Value value)
  {
  }

  Value IncantState::getResponse() const
  {
    return (m_curValue);
  }
}
