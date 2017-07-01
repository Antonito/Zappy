#ifndef MISSINGSTONESTATE_HPP_
#define MISSINGSTONESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class MissingStoneState final : public AState
  {
  public:
    MissingStoneState(std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player);
    MissingStoneState(MissingStoneState const &) = delete;
    MissingStoneState(MissingStoneState &&) = delete;
    virtual ~MissingStoneState();

    MissingStoneState &operator=(MissingStoneState const &) = delete;
    MissingStoneState &operator=(MissingStoneState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !MISSINGSTONESTATE_HPP_
