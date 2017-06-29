#ifndef AI_HPP_
#define AI_HPP_

#include <iostream>
#include <map>
#include <queue>
#include <array>
#include "IState.hpp"
#include "TCPSocket.hpp"
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

#define NB_FOOD_MIN (5)
#define NB_FOOD_NORMAL (7)

namespace ai
{
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

    void initBasicState();
    void initState();
    void send(std::string const &msg);
    void move(std::pair<std::int32_t, std::int32_t> coord);
    std::int32_t look(std::string const &object);
    std::pair<std::int32_t, std::int32_t> const
        direction(std::int32_t caseNumber);
    std::array<std::int32_t, 6> const diff(std::array<std::int32_t, 6> old,
                                           std::array<std::int32_t, 6> newTab);
    void getCurCase();

    std::int32_t m_foodUnit;
    std::array<char, 512> m_lastUnknownMsg;
    network::TCPSocket      m_sock;
    std::queue<std::string> m_cmdToSend;
    std::queue<std::string> m_cmdToRecv;
    std::array<std::unique_ptr<AState>, State::NB_STATE> m_states;
    AState *     m_curState;
    State        m_curStateName;
    Value        m_curValue;
    std::int32_t m_level;
    std::map<BasicState, std::unique_ptr<IState>> m_basicStates;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !AI_HPP_
