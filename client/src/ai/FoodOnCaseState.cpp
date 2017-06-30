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
    nope::log::Log(Debug) << "FoodOnCase[READ]State";
  }

  void FoodOnCaseState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "FoodOnCase[WRITE]State";
  }

  void FoodOnCaseState::reset(Value value)
  {
    nope::log::Log(Debug) << "FoodOnCaseState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value FoodOnCaseState::getResponse() const
  {
    return (m_curValue);
  }
}
