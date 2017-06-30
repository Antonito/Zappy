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
    FindFoodState(std::map<BasicState, std::unique_ptr<IState>> &states);
    FindFoodState(FindFoodState const &) = delete;
    FindFoodState(FindFoodState &&) = delete;
    virtual ~FindFoodState();

    FindFoodState &operator=(FindFoodState const &) = delete;
    FindFoodState &operator=(FindFoodState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    std::int32_t m_lookAround;
    bool         m_goForward;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !FINDFOODSTATE_HPP_
