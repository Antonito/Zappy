#ifndef FINDFOODSTATE_HPP_
#define FINDFOODSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class FindFoodState final : public AState
  {
  public:
    FindFoodState();
    FindFoodState(FindFoodState const &) = delete;
    FindFoodState(FindFoodState &&) = delete;
    virtual ~FindFoodState();

    FindFoodState &operator=(FindFoodState const &) = delete;
    FindFoodState &operator=(FindFoodState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  }

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FINDFOODSTATE_HPP_