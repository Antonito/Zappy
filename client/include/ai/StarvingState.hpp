#ifndef STARVINGSTATE_HPP_
#define STARVINGSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class StarvingState final : public AState
  {
  public:
    StarvingState();
    StarvingState(StarvingState const &) = delete;
    StarvingState(StarvingState &&) = delete;
    virtual ~StarvingState();

    StarvingState &operator=(StarvingState const &) = delete;
    StarvingState &operator=(StarvingState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  }

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !STARVINGSTATE_HPP_