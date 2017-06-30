#include "zappy_ai_stdafx.hpp"

namespace ai
{
  CollectStoneState::CollectStoneState(
      std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  CollectStoneState::~CollectStoneState()
  {
  }

  void CollectStoneState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "CollectStone[READ]State";
    m_states[BasicState::TAKE]->readState(readQueue);
    Value ret = m_states[BasicState::TAKE]->getResponse();
    if (ret == Value::YES)
      m_curValue = Value::YES;
    else
      m_curValue = Value::NO;
  }

  void CollectStoneState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "CollectStone[WRITE]State";
    // Change stone to the stone searched
    static_cast<TakeState *>(m_states[BasicState::TAKE])->setObject("stone");
    m_states[BasicState::TAKE]->writeState(writeQueue);
    m_canWrite = false;
  }

  void CollectStoneState::reset(Value value)
  {
    nope::log::Log(Debug) << "CollectStoneState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value CollectStoneState::getResponse() const
  {
    return (m_curValue);
  }
}
