#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FixRecipeState::FixRecipeState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  FixRecipeState::~FixRecipeState()
  {
  }

  void FixRecipeState::readState(std::queue<std::string> &readQueue)
  {
  }

  void FixRecipeState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void FixRecipeState::reset(Value value)
  {
  }

  Value FixRecipeState::getResponse() const
  {
    return (m_curValue);
  }
}
