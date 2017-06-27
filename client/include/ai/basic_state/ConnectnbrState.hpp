#ifndef CONNECTNBRSTATE_HPP_
#define CONNECTNBRSTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class ConnectnbrState final : public IState
  {
  public:
    ConnectnbrState();
    ConnectnbrState(ConnectnbrState const &) = delete;
    ConnectnbrState(ConnectnbrState &&) = delete;
    virtual ~ConnectnbrState();

    ConnectnbrState &operator=(ConnectnbrState const &) = delete;
    ConnectnbrState &operator=(ConnectnbrState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

  private:
    Value m_value;
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !CONNECTNBRSTATE_HPP_
