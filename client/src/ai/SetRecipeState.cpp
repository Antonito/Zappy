#include "zappy_ai_stdafx.hpp"

namespace ai
{
  SetRecipeState::SetRecipeState() : AState()
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