#ifndef ASTATE_HPP_
#define ASTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class AState : public IState
  {
  public:
    AState();
    AState(AState const &);
    AState(AState &&);
    virtual ~AState();

    AState &operator=(AState const &);
    AState &operator=(Astate &&);

  protected:
    std::map<State, IState *> m_states;
    State m_curState;
    Value m_curValue;
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !ASTATE_HPP_
