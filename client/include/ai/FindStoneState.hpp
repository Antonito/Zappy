#ifndef FINDSTONESTATE_HPP_
#define FINDSTONESTATE_HPP_

#include <iostream>
#include "AState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class FindStoneState final : public AState
  {
  public:
    FindStoneState(std::map<BasicState, std::unique_ptr<IState>> &states);
    FindStoneState(FindStoneState const &) = delete;
    FindStoneState(FindStoneState &&) = delete;
    virtual ~FindStoneState();

    FindStoneState &operator=(FindStoneState const &) = delete;
    FindStoneState &operator=(FindStoneState &&) = delete;

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

#endif // !FINDSTONESTATE_HPP_
