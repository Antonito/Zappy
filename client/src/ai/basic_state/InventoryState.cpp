#include "zappy_ai_stdafx.hpp"

namespace ai
{
  InventoryState::InventoryState()
  {
  }

  InventoryState::~InventoryState()
  {
  }

  void InventoryState::readState(std::queue<std::string> &readQueue)
  {
  }

  void InventoryState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "pushing Inventory to queue";
    writeQueue.push("Inventory\n");
  }

  void InventoryState::reset(Value value)
  {
  }

  Value InventoryState::getResponse() const
  {
  }

  std::int32_t InventoryState::getFood() const
  {
    return (4);
  }
}
