#ifndef MISSINGPLAYERSTATE_HPP_
#define MISSINGPLAYERSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class MissingPlayerState final : public AState
  {
  public:
    MissingPlayerState(std::map<BasicState, std::unique_ptr<IState>> &states,
                       PlayerInfo &player);
    MissingPlayerState(MissingPlayerState const &) = delete;
    MissingPlayerState(MissingPlayerState &&) = delete;
    virtual ~MissingPlayerState();

    MissingPlayerState &operator=(MissingPlayerState const &) = delete;
    MissingPlayerState &operator=(MissingPlayerState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    bool m_help;
    bool m_goAway;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !MISSINGPLAYERSTATE_HPP_
