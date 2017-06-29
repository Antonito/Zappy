#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CollectFoodState::CollectFoodState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
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
