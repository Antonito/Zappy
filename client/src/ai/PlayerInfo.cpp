#include "zappy_ai_stdafx.hpp"

namespace ai
{

  static const std::map<std::int32_t, std::string const> stoneNames = {
      {0, "linemate"}, {1, "deraumere"}, {2, "sibur"},
      {3, "mendiane"}, {4, "phiras"},    {5, "thystame"},
  };

  static const std::array<std::pair<std::int32_t, std::array<std::int32_t, 6>>,
                          7>
      recipes = {{
          {1, {{1, 0, 0, 0, 0, 0}}},
          {2, {{1, 1, 1, 0, 0, 0}}},
          {2, {{2, 0, 1, 0, 2, 0}}},
          {4, {{1, 1, 2, 0, 1, 0}}},
          {4, {{1, 2, 1, 3, 0, 0}}},
          {6, {{1, 2, 3, 0, 1, 0}}},
          {6, {{2, 2, 2, 2, 2, 1}}},
      }};

  PlayerInfo::PlayerInfo(NetworkManager &network)
      : m_inventory(), m_look(), m_level(1), m_foodTarget(-1),
        m_stoneTarget(-1), m_stoneName(""), m_network(network)
  {
  }

  PlayerInfo::PlayerInfo(PlayerInfo const &that)
      : m_inventory(that.m_inventory), m_look(that.m_look),
        m_level(that.m_level), m_foodTarget(that.m_foodTarget),
        m_stoneTarget(that.m_stoneTarget), m_stoneName(that.m_stoneName),
        m_network(that.m_network)
  {
  }

  PlayerInfo::PlayerInfo(PlayerInfo &&that)
      : m_inventory(std::move(that.m_inventory)),
        m_look(std::move(that.m_look)), m_level(std::move(that.m_level)),
        m_foodTarget(std::move(that.m_foodTarget)),
        m_stoneTarget(std::move(that.m_stoneTarget)),
        m_stoneName(std::move(that.m_stoneName)), m_network(that.m_network)
  {
  }

  PlayerInfo::~PlayerInfo()
  {
  }

  std::int32_t PlayerInfo::getLevel() const
  {
    return (m_level);
  }

  void PlayerInfo::setLevel(std::int32_t level)
  {
    m_level = level;
  }

  std::array<std::int32_t, 6> const PlayerInfo::getRecipe() const
  {
    return (recipes[static_cast<std::size_t>(m_level)].second);
  }

  std::int32_t PlayerInfo::getPlayerNbOnCase() const
  {
    return (recipes[static_cast<std::size_t>(m_level)].first);
  }

  std::array<std::int32_t, 6> const
      PlayerInfo::diff(std::array<std::int32_t, 6> const old,
                       std::array<std::int32_t, 6> const newTab) const
  {
    std::array<std::int32_t, 6> res{};
    for (std::size_t i = 0; i < 6; ++i)
      {
	res[i] = newTab[i] - old[i];
      }
    return (res);
  }

  std::array<std::int32_t, 6> const PlayerInfo::missingStone(
      std::array<std::int32_t, 6> const inventory) const
  {
    std::array<std::int32_t, 6> res{};
    for (std::size_t i = 0; i < 6; ++i)
      {
	std::int32_t tmp =
	    recipes[static_cast<std::size_t>(m_level)].second[i] -
	    inventory[i];
	if (tmp < 0)
	  res[i] = 0;
	else
	  res[i] = tmp;
      }
    return (res);
  }

  bool PlayerInfo::updateLook()
  {
    m_network.send("Look");

    std::string res = m_network.receive();

    std::replace(res.begin(), res.end(), '[', ',');
    std::replace(res.begin(), res.end(), ']', ',');

    std::stringstream        ss(res);
    std::istringstream       split(res);
    std::vector<std::string> tokens;
    std::vector<std::map<std::string, std::int32_t>> cases;

    for (std::string each; std::getline(split, each, ',');
         tokens.push_back(each))
      ;
    m_look.clear();
    for (std::size_t i = 0; i < tokens.size(); ++i)
      {
	if (i == 0)
	  continue;
	std::map<std::string, std::int32_t> mapTemp;
	mapTemp["player"] = 0;
	mapTemp["food"] = 0;
	mapTemp["linemate"] = 0;
	mapTemp["deraumere"] = 0;
	mapTemp["sibur"] = 0;
	mapTemp["mendiane"] = 0;
	mapTemp["phiras"] = 0;
	mapTemp["thystame"] = 0;
	std::stringstream iss(tokens[i]);
	std::string       resource;
	while (iss >> resource)
	  {
	    mapTemp[resource] += 1;
	  }
	m_look.push_back(std::move(mapTemp));
      }

      // TODO: remove
//     {
//       nope::log::LogMessage msg = nope::log::Log(Debug);
//       msg << "[";
//       for (std::map<std::string, std::int32_t> &tile : m_look)
// 	{
// 	  for (std::pair<const std::string, std::int32_t> &r : tile)
// 	    {
// 	      for (std::int32_t i = 0; i < r.second; ++i)
// 		{
// 		  msg << ' ' << r.first;
// 		}
// 	    }
// 	  msg << ", ";
// 	}
//       msg << "]";
//     }
    return (true);
  }

  bool PlayerInfo::updateInventory()
  {
    m_network.send("Inventory");

    std::string msg = m_network.receive();

    std::stringstream ss(msg);
    std::string       trash;

    std::string res;

    for (std::int32_t i = 0; i < 7; ++i)
      {
	ss >> trash;
	ss >> res;
	ss >> m_inventory[res];
      }

    return (true);
  }

  bool PlayerInfo::broadcast(std::string const &)
  {
    return (false);
  }

  bool PlayerInfo::connectNbr()
  {
    return (false);
  }

  bool PlayerInfo::eject()
  {
    return (false);
  }

  bool PlayerInfo::fork()
  {
    return (false);
  }

  bool PlayerInfo::forward()
  {
    m_network.send("Forward");

    return (m_network.receive() == "ok");
  }

  bool PlayerInfo::incant()
  {
    return (false);
  }

  bool PlayerInfo::left()
  {
    m_network.send("Left");

    return (m_network.receive() == "ok");
  }

  bool PlayerInfo::right()
  {
    m_network.send("Right");

    return (m_network.receive() == "ok");
  }

  bool PlayerInfo::set(std::string const &resource)
  {
    m_network.send("Set " + resource);

    if (m_network.receive() == "ok")
      {
	m_inventory[resource]--;
	return (true);
      }
    else
      {
	return (false);
      }
  }

  bool PlayerInfo::take(std::string const &resource)
  {
    m_network.send("Take " + resource);

    if (m_network.receive() == "ok")
      {
	m_inventory[resource]++;
	return (true);
      }
    else
      {
	return (false);
      }
  }

  std::int32_t PlayerInfo::get(std::string const &res) const
  {
    return (m_inventory.at(res));
  }

  std::int32_t PlayerInfo::find(std::string const &res) const
  {
    for (std::size_t i = 0; i < m_look.size(); ++i)
      {
	if (m_look[i].at(res) > 0)
	  {
	    return (static_cast<std::int32_t>(i));
	  }
      }
    return (-1);
  }

  bool PlayerInfo::moveTo(std::int32_t x, std::int32_t y)
  {
    bool res = true;

    for (std::int32_t i = 0; i < y; ++i)
      {
	if (!this->forward())
	  {
	    res = false;
	  }
      }

    if (x > 0)
      {
	if (!this->right())
	  {
	    res = false;
	  }
      }
    else if (x < 0)
      {
	if (!this->left())
	  {
	    res = false;
	  }
      }

    for (std::int32_t i = 0; i < x; ++i)
      {
	if (!this->forward())
	  {
	    res = false;
	  }
      }
    return (res);
  }

  void PlayerInfo::setFoodTarget(std::int32_t target)
  {
    m_foodTarget = target;
  }

  std::int32_t PlayerInfo::getFoodTarget() const
  {
    return (m_foodTarget);
  }

  void PlayerInfo::setStoneTarget(std::int32_t target)
  {
    m_stoneTarget = target;
  }

  void PlayerInfo::setStoneName(std::string const &name)
  {
    m_stoneName = name;
  }

  std::string const &PlayerInfo::getStoneName() const
  {
    return (m_stoneName);
  }

  std::int32_t PlayerInfo::getStoneTarget() const
  {
    return (m_stoneTarget);
  }

  std::pair<std::int32_t, std::int32_t>
      PlayerInfo::getDirection(std::int32_t pos) const
  {
    std::int32_t x = 0;
    std::int32_t y = 0;
    std::int32_t mid = 0;

    for (y = 0; pos > mid + y; ++y)
      {
	mid += 2 * (y + 1);
      }
    x = pos - mid;
    nope::log::Log(Debug) << "Direction of " << pos << ": " << x << ' ' << y << "(" << mid << ")";
    return (std::pair<std::int32_t, std::int32_t>(x, y));
  }

  std::string const PlayerInfo::getNameForIdStone(std::int32_t id) const
  {
    return (stoneNames.at(id));
  }
}
