#ifndef FIXRECIPESTATE_HPP_
#define FIXRECIPESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class FixRecipeState final : public AState
  {
  public:
    FixRecipeState(std::map<BasicState, std::unique_ptr<IState>> &states);
    FixRecipeState(FixRecipeState const &) = delete;
    FixRecipeState(FixRecipeState &&) = delete;
    virtual ~FixRecipeState();

    FixRecipeState &operator=(FixRecipeState const &) = delete;
    FixRecipeState &operator=(FixRecipeState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FIXRECIPESTATE_HPP_
