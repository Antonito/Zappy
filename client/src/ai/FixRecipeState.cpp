#include "zappy_ai_stdafx.hpp"

namespace ai
{
  FixRecipeState::FixRecipeState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player)
  {
  }

  FixRecipeState::~FixRecipeState()
  {
  }

  void FixRecipeState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "FixRecipe[READ]State";
  }

  void FixRecipeState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "FixRecipe[WRITE]State";
  }

  void FixRecipeState::reset(Value value)
  {
    nope::log::Log(Debug) << "FixRecipeState reset";
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value FixRecipeState::getResponse() const
  {
    return (m_curValue);
  }
}
