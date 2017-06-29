#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FindFoodState::FindFoodState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  FindFoodState::~FindFoodState()
  {
  }

  void FindFoodState::readState(std::queue<std::string> &readQueue)
  {
  }

  void FindFoodState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void FindFoodState::reset(Value value)
  {
  }

  Value FindFoodState::getResponse() const
  {
    return (m_curValue);
  }
}
