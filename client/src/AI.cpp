#include "AI.hpp"

namespace ai
{
  static std::map<State, std::array<State, Value::NB_VALUE>> transitionTable =
      {
          {STARVING,
           {FOOD_ON_CASE, RECEIVE_MSG, NO_CHANGE, NO_CHANGE, MISSING_STONE,
            MISSING_PLAYER, RECEIVE_MSG, NO_CHANGE}},

  };

  AI::AI() : m_actionForState();
  {
    initAction();
  }

  AI::AI(AI const &that) : m_actionForState(that.m_actionForState)
  {
  }

  AI::~AI()
  {
  }

  void AI::initAction()
  {
  }
}