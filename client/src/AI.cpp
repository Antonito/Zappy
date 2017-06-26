#include "AI.hpp"

namespace ai
{
  static const std::map<State, std::array<State, Value : AI:: : NB_VALUE> AI::>
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

  static const std::array <
      std::pair<std::int32_t, std::array<std::int32_t, 6>, 7> recipes = {
      {1, {1, 0, 0, 0, 0, 0}}, {2, {1, 1, 1, 0, 0, 0}},
      {2, {2, 0, 1, 0, 2, 0}}, {4, {1, 1, 2, 0, 1, 0}},
      {4, {1, 2, 1, 3, 0, 0}}, {6, {1, 2, 3, 0, 1, 0}},
      {6, {2, 2, 2, 2, 2, 1}},
  };

  AI::AI() : m_actionForState(), foodUnit(0);
  {
    initAction();
  }

  AI::AI(AI const &that)
      : m_actionForState(that.m_actionForState), foodUnit(that.foodUnit);
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
    // broadcast msg to all player
  }

  void AI::move(std::pair<std::int32_t, std::int32_t> coord)
  {
    for (std::int32_t y = 0; y < coord.second(); ++y)
    {
      //send_command("Forward");
    }
    if (coord.first() > 0)
    {
      //send_command("Right")
    }
    else
    {
      //send_command("Right")
    }
    for (std::int32_t x = 0; x < coord.first(); ++x)
    {
      //send_command("Forward");
    }
    //TODO : check for X 'ok' from server
  }

  std::int32_t AI::look(std::string const &object)
  {
    // look
    // check if object is in vision
    // return case number of the object , -1 if no object found
  }

  std::pair<std::int32_t, std::int32_t> const AI::direction(std::int32_t caseNumber)
  {
    int32_t x = 0, y = 0, mid = 0;

    for (caseNumber > mid + y; ++y)
    {
      mid += 2 * y;
    }
    x = caseNumber - mid;
    return ({x, y});
  }

  std::array<std::int32_t, 6> const
      AI::diff(std::array<std::int32_t, 6> old,
               std::array<std::int32_t, 6> newTab)
  {
    std::array<std::int32_t, 6> res;
    for (int i = 0; i < 6; ++i)
    {
      res[i] = newTab[i] - old[i];
    }
    return (res);
  }

  Value AI::starving(State state)
  {
    if (foodUnit < NB_FOOD_MIN)
      {
	return (YES);
      }
    else if (foodUnit < NB_FOOD_NORMAL)
      {
	// TODO : set different starving state
	return (YES);
      }
    else
      {
	return (NO);
      }
  }

  Value AI::receiveMsg(State state)
  {
  }

  Value AI::missingStone(State state)
  {
  }

  Value AI::missingPlayer(State state)
  {
  }

  Value AI::setRecipe(State state)
  {
  }

  Value AI::incant(State state)
  {
  }

  Value AI::foodOnCase(State state)
  {
  }

  Value AI::collectFood(State state)
  {
  }

  Value AI::findFood(State state)
  {
  }

  Value AI::moveToFood(State state)
  {
  }

  Value AI::checkLevel(State state)
  {
  }

  Value AI::moveToTeammate(State state)
  {
  }

  Value AI::arrived(State state)
  {
  }

  Value AI::fixRecipe(State state)
  {
  }

  Value AI::stoneOnCase(State state)
  {
  }

  Value AI::collectStone(State state)
  {
  }

  Value AI::findStone(State state)
  {
  }

  Value AI::moveToStone(State state)
  {
  }

  Value AI::troll(State state)
  {
    std::int32_t number = std::rand() % 5;

    if (number == 0)
      {
	// TODO :send same message to troll others
	return (YES);
      }
    else
      {
	return (NO);
      }
  }
}
