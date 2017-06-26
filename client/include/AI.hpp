#ifndef AI_HPP_
#define AI_HPP_

namespace ai
{
  enum class Value : std::int8_t
  {
    YES,
    NO,
    COME,
    GO_AWAY,
    SEARCH,
    WAINTING,
    READY,
    END_INCANT,
    NB_VALUE,
  };

  enum class State : std::int8_t
  {
    NO_CHANGE = -1,
    DEAD,
    STARVING,
    RECEIVE_MSG,
    MISSING_STONE,
    MISSING_PLAYER,
    SET_RECIPE,
    INCANT,
    FOOD_ON_CASE,
    COLLECT_FOOD,
    FIND_FOOD,
    MOVE_TO_FOOD,
    LEVEL,
    MOVE_TO_TEAMMATE,
    ARRIVED,
    FIX_RECIPE,
    STONE_ON_CASE,
    COLLECT_STONE,
    FIND_STONE,
    MOVE_TO_STONE,
    TROLL,
    NB_STATE,
  };

  class AI
  {
  public:
    AI();
    AI(AI const &);
    AI(AI const &&) = delete;
    ~AI();

    AI &operator=(AI const &) = delete;
    AI &operator=(AI const &&) = delete;

  private:
    void initAction();
    void send(std::string const &msg);

    Value starving((State state = State::NO_CHANGE));
    Value receiveMsg((State state = State::NO_CHANGE));
    Value missingStone((State state = State::NO_CHANGE));
    Value missingPlayer((State state = State::NO_CHANGE));
    Value setRecipe((State state = State::NO_CHANGE));
    Value incant((State state = State::NO_CHANGE));
    Value foodOnCase((State state = State::NO_CHANGE));
    Value collectFood((State state = State::NO_CHANGE));
    Value findFood((State state = State::NO_CHANGE));
    Value moveToFood((State state = State::NO_CHANGE));
    Value checkLevel((State state = State::NO_CHANGE));
    Value moveToTeammate((State state = State::NO_CHANGE));
    Value arrived((State state = State::NO_CHANGE));
    Value fixRecipe((State state = State::NO_CHANGE));
    Value stoneOnCase((State state = State::NO_CHANGE));
    Value collectStone((State state = State::NO_CHANGE));
    Value findStone((State state = State::NO_CHANGE));
    Value moveToStone((State state = State::NO_CHANGE));
    Value troll((State state = State::NO_CHANGE));

    std::map<State, State (AI::*)(State)> m_actionForState;
  };
}

#endif // !AI_HPP_