#ifndef SETRECIPESTATE_HPP_
#define SETRECIPESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class SetRecipeState final : public AState
  {
  public:
    SetRecipeState();
    SetRecipeState(SetRecipeState const &) = delete;
    SetRecipeState(SetRecipeState &&) = delete;
    virtual ~SetRecipeState();

    SetRecipeState &operator=(SetRecipeState const &) = delete;
    SetRecipeState &operator=(SetRecipeState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;
  }

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !SETRECIPESTATE_HPP_