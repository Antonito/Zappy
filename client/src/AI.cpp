#include "AI.hpp"

namespace ai
{
  static const std::map<State, std::array<State, Value::NB_VALUE>>
      transitionTable = {
          {STARVING,
           {FOOD_ON_CASE, RECEIVE_MSG, NO_CHANGE, NO_CHANGE, MISSING_STONE,
            MISSING_PLAYER, RECEIVE_MSG, NO_CHANGE}},
          {RECEIVE_MSG,
           {NO_CHANGE, MISSING_STONE, LEVEL, MISSING_STONE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, MISSING_STONE}},
          {MISSING_STONE,
           {STONE_ON_CASE, MISSING_PLAYER, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {MISSING_PLAYER,
           {NO_CHANGE, SET_RECIPE, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE}},
          {SET_RECIPE,
           {INCANT, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE}},
          {INCANT,
           {STARVING, MISSING_STONE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {FOOD_ON_CASE,
           {COLLECT_FOOD, FIND_FOOD, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {COLLECT_FOOD,
           {STARVING, FOOD_ON_CASE, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE}},
          {FIND_FOOD,
           {MOVE_TO_FOOD, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {MOVE_TO_FOOD,
           {FOOD_ON_CASE, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {LEVEL,
           {MOVE_TO_TEAMMATE, MISSING_STONE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {MOVE_TO_TEAMMATE,
           {ARRIVED, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE}},
          {ARRIVED,
           {FIX_RECIPE, STARVING, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            STARVING, NO_CHANGE}},
          {FIX_RECIPE,
           {ARRIVED, ARRIVED, NO_CHANGE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE}},
          {STONE_ON_CASE,
           {COLECT_STONE, FIND_STONE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {COLLECT_STONE,
           {STARVING, STONE_ON_CASE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {FIND_STONE,
           {MOVE_TO_STONE, NO_CHANGE, NO_CHANGE, NO_CHANGE, STARVING,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {MOVE_TO_STONE,
           {STONE_ON_CASE, NO_CHANGE, NO_CHANGE, NO_CHANGE, STARVING,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
          {TROLL,
           {MISSING_STONE, MISSING_STONE, NO_CHANGE, NO_CHANGE, NO_CHANGE,
            NO_CHANGE, NO_CHANGE, NO_CHANGE}},
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
    m_actionForState.emplace(STARVING, &AI::starving);
    m_actionForState.emplace(RECEIVE_MSG, &AI::receiveMsg);
    m_actionForState.emplace(MISSING_STONE, &AI::missingStone);
    m_actionForState.emplace(MISSING_PLAYER, &AI::missinPlayer);
    m_actionForState.emplace(SET_RECIPE, &AI::setRecipe);
    m_actionForState.emplace(INCANT, &AI::incant);
    m_actionForState.emplace(FOOD_ON_CASE, &AI::foodOnCase);
    m_actionForState.emplace(COLLECT_FOOD, &AI::collectFood);
    m_actionForState.emplace(FIND_FOOD, &AI::findFood);
    m_actionForState.emplace(MOVE_TO_FOOD, &AI::moveToFood);
    m_actionForState.emplace(LEVEL, &AI::checkLevel);
    m_actionForState.emplace(MOVE_TO_TEAMMATE, &AI::moveToTeammate);
    m_actionForState.emplace(ARRIVED, &AI::arrived);
    m_actionForState.emplace(FIX_RECIPE, &AI::fixRecipe);
    m_actionForState.emplace(STONE_ON_CASE, &AI::stoneOnCase);
    m_actionForState.emplace(COLLECT_STONE, &AI::collectStone);
    m_actionForState.emplace(FIND_STONE, &AI::findStone);
    m_actionForState.emplace(MOVE_TO_STONE, &AI::moveToStone);
    m_actionForState.emplace(TROLL, &AI::troll);
  }

  void AI::send(std::string const &msg)
  {
  }

  Value starving(State state)
  {
  }

  Value receiveMsg(State state)
  {
  }

  Value missingStone(State state)
  {
  }

  Value missingPlayer(State state)
  {
  }

  Value setRecipe(State state)
  {
  }

  Value incant(State state)
  {
  }

  Value foodOnCase(State state)
  {
  }

  Value collectFood(State state)
  {
  }

  Value findFood(State state)
  {
  }

  Value moveToFood(State state)
  {
  }

  Value checkLevel(State state)
  {
  }

  Value moveToTeammate(State state)
  {
  }

  Value arrived(State state)
  {
  }

  Value fixRecipe(State state)
  {
  }

  Value stoneOnCase(State state)
  {
  }

  Value collectStone(State state)
  {
  }

  Value findStone(State state)
  {
  }

  Value moveToStone(State state)
  {
  }

  Value troll(State state)
  {
  }
}