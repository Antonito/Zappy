#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LevelState::LevelState(std::map<BasicState, std::unique_ptr<IState>> &states)
      : AState(states)
  {
  }

  LevelState::~LevelState()
  {
  }

  void LevelState::readState(std::queue<std::string> &readQueue)
  {
  }

  void LevelState::writeState(std::queue<std::string> &writeQueue)
  {
  }

  void LevelState::reset(Value value)
  {
  }

  Value LevelState::getResponse() const
  {
    return (m_curValue);
  }
}
