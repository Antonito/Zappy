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
    nope::log::Log(Debug) << "CollectFood[READ]State";
    m_states[BasicState::TAKE]->readState(readQueue);
    Value ret = m_states[BasicState::TAKE]->getResponse();
    if (ret == Value::YES)
      m_curValue = Value::YES;
    else
      m_curValue = Value::NO;
  }

  void CollectFoodState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "CollectFood[WRITE]State";
    static_cast<TakeState *>(m_states[BasicState::TAKE])->setObject("food");
    m_states[BasicState::TAKE]->writeState(writeQueue);
    m_canWrite = false;
  }

  void CollectFoodState::reset(Value value)
  {
    nope::log::Log(Debug) << "CollectFoodState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value CollectFoodState::getResponse() const
  {
    return (m_curValue);
  }
}
