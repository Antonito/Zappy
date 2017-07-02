#include "zappy_ai_stdafx.hpp"

namespace ai
{
  InventoryState::InventoryState() : m_value(Value::NO), m_inventory()
  {
  }

  InventoryState::~InventoryState()
  {
  }

  void InventoryState::readState(std::queue<std::string> &readQueue)
  {
    nope::log::Log(Debug) << "Inventory[READ]BasicState";
    if (readQueue.empty())
      {
	m_value = Value::NO;
	return;
      }
    m_value = Value::YES;
    std::string iss(readQueue.front());
    readQueue.pop();

    // std::string iss("[ food 9, linemate 0, deraumere 0, sibur 0, mendiane 0,
    // phiras 0, thystame 0 ]");
    std::stringstream ss;
    std::string       trash;
    ss << iss;

    std::string res;
    int         a;

    for (std::int32_t i = 0; i < 7; ++i)
      {
	ss >> trash;
	ss >> res;
	ss >> a;
	m_inventory[res] = a;
      }
  }

  void InventoryState::writeState(std::queue<std::string> &writeQueue)
  {
    nope::log::Log(Debug) << "Inventory[WRITE]BasicState";
    nope::log::Log(Debug) << "pushing Inventory to queue";
    writeQueue.push("Inventory\n");
  }

  void InventoryState::reset(Value value)
  {
    m_value = value;
  }

  Value InventoryState::getResponse() const
  {
    return (m_value);
  }

  std::int32_t InventoryState::getFood() const
  {
    return (m_inventory.at("food"));
  }

  std::int32_t InventoryState::getLinemate() const
  {
    return (m_inventory.at("linemate"));
  }

  std::int32_t InventoryState::getDeraumere() const
  {
    return (m_inventory.at("deraumere"));
  }

  std::int32_t InventoryState::getSibur() const
  {
    return (m_inventory.at("sibur"));
  }

  std::int32_t InventoryState::getMendiane() const
  {
    return (m_inventory.at("mendiane"));
  }

  std::int32_t InventoryState::getPhiras() const
  {
    return (m_inventory.at("phiras"));
  }

  std::int32_t InventoryState::getThystame() const
  {
    return (m_inventory.at("thystame"));
  }

  std::array<std::int32_t, 6> const InventoryState::getInventory() const
  {
    std::array<std::int32_t, 6> tmp;

    tmp[0] = m_inventory.at("linemate");
    tmp[1] = m_inventory.at("deraumere");
    tmp[2] = m_inventory.at("sibur");
    tmp[3] = m_inventory.at("mendiane");
    tmp[4] = m_inventory.at("phiras");
    tmp[5] = m_inventory.at("thystame");

    return (tmp);
  }
}
