#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CollectFoodState::CollectFoodState() : AState()
  {
  }

  CollectFoodState::~CollectFoodState()
  {
  }

  void CollectFoodState::readState(std::queue<std::string> &readQueue)
  {
  }

  void CollectFoodState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void CollectFoodState::reset(Value value)
  {
  }

  Value CollectFoodState::getResponse() const
  {
    return (m_curValue);
  }
}