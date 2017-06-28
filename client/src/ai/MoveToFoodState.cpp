#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MoveToFoodState::MoveToFoodState(std::map<BasicState, IState *> &states) : AState(states)
  {
  }

  MoveToFoodState::~MoveToFoodState()
  {
  }

  void MoveToFoodState::readState(std::queue<std::string> &readQueue)
  {
  }

  void MoveToFoodState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void MoveToFoodState::reset(Value value)
  {
  }

  Value MoveToFoodState::getResponse() const
  {
    return (m_curValue);
  }
}
