#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FoodOnCaseState::FoodOnCaseState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  FoodOnCaseState::~FoodOnCaseState()
  {
  }

  void FoodOnCaseState::readState(std::queue<std::string> &readQueue)
  {
  }

  void FoodOnCaseState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void FoodOnCaseState::reset(Value value)
  {
  }

  Value FoodOnCaseState::getResponse() const
  {
    return (m_curValue);
  }
}
