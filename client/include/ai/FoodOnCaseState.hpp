#ifndef FOODONCASESTATE_HPP_
#define FOODONCASESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class FoodOnCaseState final : public AState
  {
  public:
    FoodOnCaseState(std::map<BasicState, std::unique_ptr<IState>> &states);
    FoodOnCaseState(FoodOnCaseState const &) = delete;
    FoodOnCaseState(FoodOnCaseState &&) = delete;
    virtual ~FoodOnCaseState();

    FoodOnCaseState &operator=(FoodOnCaseState const &) = delete;
    FoodOnCaseState &operator=(FoodOnCaseState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FOODONCASESTATE_HPP_
