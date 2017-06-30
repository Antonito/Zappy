#include "zappy_ai_stdafx.hpp"

namespace ai
{
  MoveToFoodState::MoveToFoodState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  MoveToFoodState::~MoveToFoodState()
  {
  }

  void MoveToFoodState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "MoveToFood[READ]State";
  }

  void MoveToFoodState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "MoveToFood[WRITE]State";
  }

  void MoveToFoodState::reset(Value value)
  {
    nope::log::Log(Debug) << "MoveToFoodState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value MoveToFoodState::getResponse() const
  {
    return (m_curValue);
  }
}
