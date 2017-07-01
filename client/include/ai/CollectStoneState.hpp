#ifndef COLLECTSTONESTATE_HPP_
#define COLLECTSTONESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class CollectStoneState final : public AState
  {
  public:
    CollectStoneState(std::map<BasicState, std::unique_ptr<IState>> &states, PlayerInfo &player);
    CollectStoneState(CollectStoneState const &) = delete;
    CollectStoneState(CollectStoneState &&) = delete;
    virtual ~CollectStoneState();

    CollectStoneState &operator=(CollectStoneState const &) = delete;
    CollectStoneState &operator=(CollectStoneState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !COLLECTSTONESTATE_HPP_
