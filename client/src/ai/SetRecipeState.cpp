#include "zappy_ai_stdafx.hpp"

namespace ai
{
  SetRecipeState::SetRecipeState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  SetRecipeState::~SetRecipeState()
  {
  }

  void SetRecipeState::readState(std::queue<std::string> &readQueue)
  {
  }

  void SetRecipeState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void SetRecipeState::reset(Value value)
  {
  }

  Value SetRecipeState::getResponse() const
  {
    return (m_curValue);
  }
}
