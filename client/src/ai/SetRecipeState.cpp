#include "zappy_ai_stdafx.hpp"

namespace ai
{
  SetRecipeState::SetRecipeState(
      std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player)
      : AState(states, player), m_fixTab()
  {
    for (std::size_t i = 0; i < 6; ++i)
    {
      m_fixTab[i] = 0;
    }
  }

  SetRecipeState::~SetRecipeState()
  {
  }

  void SetRecipeState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "SetRecipe[READ]State";
    m_states[BasicState::LOOK]->readState(readQueue);
    Value ret = m_states[BasicState::LOOK]->getResponse();
    std::array<std::int32_t, 6> cmpTable = m_player.diff(m_player.getRecipe(), static_cast<LookState *>(m_states[BasicState::LOOK])->getCurStones());
    std::int32_t count = 0;
    for (std::size_t i = 0; i < 6; ++i)
    {
      if (cmpTable[i] > 0)
      {
        m_states[BasicState::TAKE]->readState(readQueue);
        m_fixTab[i] = 1;
      }
      else if (cmpTable[i] < 0)
      {
        m_states[BasicState::SET]->readState(readQueue);
        m_fixTab[i] = 2;
      }
      else
      {
        m_fixTab[i] = 0;
        ++count;
      }
    }
    if (count == 6)
    {
      m_curValue = Value::YES;
    }
  }

  void SetRecipeState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "SetRecipe[WRITE]State";
    m_states[BasicState::LOOK]->reset(Value::NO);
    m_states[BasicState::LOOK]->writeState(writeQueue);
    for (std::size_t i = 0; i < 6; ++i)
    {
      if (m_fixTab[i] == 1)
      {
        m_states[BasicState::TAKE]->writeState(writeQueue);
      }
      else if (m_fixTab[i] == 2)
      {
        m_states[BasicState::SET]->writeState(writeQueue);
      }
      m_fixTab[i] = 0;
    }
    m_canWrite = false;
  }

  void SetRecipeState::reset(Value value)
  {
    nope::log::Log(Debug) << "SetRecipeState reset";
    for (std::size_t i = 0; i < 6; ++i)
    {
      m_fixTab[i] = 0;
    }
    m_curValue = Value::LOOP;
    m_retValue = value;
    m_canWrite = true;
  }

  Value SetRecipeState::getResponse() const
  {
    return (m_curValue);
  }
}
