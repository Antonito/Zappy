#include "zappy_ai_stdafx.hpp"

namespace ai
{
  LevelState::LevelState(std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  LevelState::~LevelState()
  {
  }

  void LevelState::readState(std::queue<std::string> &readQueue)
  {
    m_curValue = Value::YES;
    nope::log::Log(Debug) << "Level[READ]State";
  }

  void LevelState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Level[WRITE]State";
    m_curValue = Value::YES;
  }

  void LevelState::reset(Value value)
  {
    nope::log::Log(Debug) << "LevelState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value LevelState::getResponse() const
  {
    return (m_curValue);
  }
}
