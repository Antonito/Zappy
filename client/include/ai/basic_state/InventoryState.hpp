#ifndef INVENTORYSTATE_HPP_
#define INVENTORYSTATE_HPP_

#include <iostream>
#include "ai/IState.hpp"

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

  private:
    Value m_value;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !INVENTORYSTATE_HPP_

