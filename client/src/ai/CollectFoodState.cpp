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
    m_states[BasicState::TAKE]->readState(readQueue);
  }

  void CollectFoodState::writeState(std::queue<std::string> &writeQueue)
  {
    static_cast<TakeState *>(m_states[BasicState::TAKE])->setObject("food");;
    m_states[BasicState::TAKE]->writeState(writeQueue);
  }

  void CollectFoodState::reset(Value value)
  {
  }

  Value CollectFoodState::getResponse() const
  {
    return (m_curValue);
  }
}
