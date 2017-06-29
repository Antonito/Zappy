#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CheckMessageState::CheckMessageState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  CheckMessageState::~CheckMessageState()
  {
  }

  void CheckMessageState::readState(std::queue<std::string> &readQueue)
  {
  }

  void CheckMessageState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void CheckMessageState::reset(Value value)
  {
  }

  Value CheckMessageState::getResponse() const
  {
    return (m_curValue);
  }
}
