#ifndef AI_HPP_
#define AI_HPP_

#include <map>
#include <queue>
#include <array>
#include "TCPSocket.hpp"

#define NB_FOOD_MIN (5)
#define NB_FOOD_NORMAL (7)

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
    explicit AI(std::string ip, std::uint16_t port);
    AI(AI const &) = delete;
    AI(AI const &&) = delete;
    ~AI();

    AI &operator=(AI const &) = delete;
    AI &operator=(AI const &&) = delete;

  private:
    std::int32_t checkActivity(fd_set &readfds, fd_set &writefds);
    std::int32_t treatIncomingData();
    std::int32_t treatOutcomingData();
    std::int32_t loop();

    void initAction();
    void send(std::string const &msg);
    void move(std::pair<std::int32_t, std::int32_t> coord);
    std::int32_t look(std::string const &object);
    std::pair<std::int32_t, std::int32_t> const direction(std::int32_t caseNumber);
    std::array<std::int32_t, 6> const diff(std::array<std::int32_t, 6> old,
                                           std::array<std::int32_t, 6> newTab);

    Value starving(ai::State state = ai::State::NO_CHANGE);
    Value receiveMsg(ai::State state = State::NO_CHANGE);
    Value missingStone(ai::State state = State::NO_CHANGE);
    Value missingPlayer(ai::State state = State::NO_CHANGE);
    Value setRecipe(ai::State state = State::NO_CHANGE);
    Value incant(ai::State state = State::NO_CHANGE);
    Value foodOnCase(ai::State state = State::NO_CHANGE);
    Value collectFood(ai::State state = State::NO_CHANGE);
    Value findFood(ai::State state = State::NO_CHANGE);
    Value moveToFood(ai::State state = State::NO_CHANGE);
    Value checkLevel(ai::State state = State::NO_CHANGE);
    Value moveToTeammate(ai::State state = State::NO_CHANGE);
    Value arrived(ai::State state = State::NO_CHANGE);
    Value fixRecipe(ai::State state = State::NO_CHANGE);
    Value stoneOnCase(ai::State state = State::NO_CHANGE);
    Value collectStone(ai::State state = State::NO_CHANGE);
    Value findStone(ai::State state = State::NO_CHANGE);
    Value moveToStone(ai::State state = State::NO_CHANGE);
    Value troll(ai::State state = State::NO_CHANGE);

    std::map<State, State (AI::*)(State)> m_actionForState;
    std::int32_t m_foodUnit;
    std::array<char, 512> m_lastUnknownMsg;
    network::TCPSocket m_sock;
    std::queue<std::array<char, 512> > m_cmdToSend;
    std::queue<std::array<char, 512> > m_cmdToRecv;
  };
}

#endif // !AI_HPP_
