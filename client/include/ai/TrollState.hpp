#ifndef TROLLSTATE_HPP_
#define TROLLSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class TrollState final : public AState
  {
  public:
    TrollState(std::map<BasicState, std::unique_ptr<IState>> &states);
    TrollState(TrollState const &) = delete;
    TrollState(TrollState &&) = delete;
    virtual ~TrollState();

    TrollState &operator=(TrollState const &) = delete;
    TrollState &operator=(TrollState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !TROLLSTATE_HPP_
