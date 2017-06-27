#ifndef COLLECTFOODSTATE_HPP_
#define COLLECTFOODSTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class CollectFoodState final : public AState
  {
  public:
    CollectFoodState();
    CollectFoodState(CollectFoodState const &) = delete;
    CollectFoodState(CollectFoodState &&) = delete;
    virtual ~CollectFoodState();

    CollectFoodState &operator=(CollectFoodState const &) = delete;
    CollectFoodState &operator=(CollectFoodState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !COLLECTFOODSTATE_HPP_

