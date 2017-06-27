#ifndef LEVELSTATE_HPP_
#define LEVELSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class LevelState final : public AState
  {
  public:
    LevelState();
    LevelState(LevelState const &) = delete;
    LevelState(LevelState &&) = delete;
    virtual ~LevelState();

    LevelState &operator=(LevelState const &) = delete;
    LevelState &operator=(LevelState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  }

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !LEVELSTATE_HPP_