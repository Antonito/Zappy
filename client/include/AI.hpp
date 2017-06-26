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

    Value starving();
    Value receiveMsg();
    Value missingStones();
    Value missingPlayers();
    Value setRecipe();
    Value incant();
    Value foodOnCase();
    Value CollectFood();
    Value findFood();
    Value moveToFood();
    Value checkLevel();
    Value moveToTeammate();
    Value arrived();
    Value fixRecipe();
    Value stoneOnCase();
    Value collectStone();
    Value findStone();
    Value moveStone();
    Value troll();

    std::vector<State, State (AI::*)(State state = State::NO_CHANGE)>
        m_actionForState;
  };
}

#endif // !AI_HPP_