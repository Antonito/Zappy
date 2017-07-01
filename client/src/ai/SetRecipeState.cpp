#include "zappy_ai_stdafx.hpp"

namespace ai
{
  SetRecipeState::SetRecipeState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  SetRecipeState::~SetRecipeState()
  {
  }

  void SetRecipeState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "SetRecipe[READ]State";
  }

  void SetRecipeState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "SetRecipe[WRITE]State";
  }

  void SetRecipeState::reset(Value value)
  {
    nope::log::Log(Debug) << "SetRecipeState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value SetRecipeState::getResponse() const
  {
    return (m_curValue);
  }
}
