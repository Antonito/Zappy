#ifndef INVENTORYSTATE_HPP_
#define INVENTORYSTATE_HPP_

#include <iostream>
#include <sstream>
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

    std::int32_t getFood() const;
    std::int32_t getLinemate() const;
    std::int32_t getDeraumere() const;
    std::int32_t getSibur() const;
    std::int32_t getMendiane() const;
    std::int32_t getPhiras() const;
    std::int32_t getThystame() const;

  private:
    Value m_value;
    std::map<std::string, std::int32_t> m_inventory;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !INVENTORYSTATE_HPP_
