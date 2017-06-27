#ifndef TAKESTATE_HPP_
#define TAKESTATE_HPP_

#include <iostream>
#include "IState.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class InventoryState final : public IState
  {
  public:
    InventoryState();
    InventoryState(InventoryState const &) = delete;
    InventoryState(InventoryState &&) = delete;
    virtual ~InventoryState();

    InventoryState &operator=(InventoryState const &) = delete;
    InventoryState &operator=(InventoryState &&) = delete;

    virtual void readState(std::queue<std::string> &readQueue);
    virtual void writeState(std::queue<std::string> &writeQueue);
    virtual void reset(Value value);
    virtual Value getResponse() const;

    void setObject(std::string const &);

  private:
    Value        m_value;
    std::string &m_object;
  }
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !TAKESTATE_HPP_
