#ifndef PLAYERINFO_HPP_
#define PLAYERINFO_HPP_

#include <iostream>
#include <queue>
#include <map>
#include <vector>
#include "NetworkManager.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif

namespace ai
{
  class PlayerInfo
  {
  public:
    PlayerInfo(NetworkManager &);
    PlayerInfo(PlayerInfo const &);
    PlayerInfo(PlayerInfo &&);
    ~PlayerInfo();

    PlayerInfo &operator=(PlayerInfo const &) = delete;
    PlayerInfo &operator=(PlayerInfo &&) = delete;

    std::int32_t getLevel() const;
    void         setLevel(std::int32_t);

    std::array<std::int32_t, 6> const getRecipe() const;

    std::int32_t getNbPlayerForRecipe() const;

    std::int32_t getNbPlayerOnCase() const;

    std::array<std::int32_t, 6> const
        diff(std::array<std::int32_t, 6> const old,
             std::array<std::int32_t, 6> const newTab) const;
    std::array<std::int32_t, 6> const
        missingStone(std::array<std::int32_t, 6> const inventory) const;

    bool updateLook();
    bool updateInventory();
    bool broadcast(std::string const &);
    bool connectNbr();
    bool eject();
    bool fork();
    bool forward();
    bool incant();
    bool left();
    bool right();
    bool set(std::string const &);
    bool take(std::string const &);

    std::int32_t get(std::string const &res) const;
    std::int32_t find(std::string const &res) const;

    bool moveTo(std::int32_t x, std::int32_t y);

    void setFoodTarget(std::int32_t target);
    std::int32_t getFoodTarget() const;

    void setStoneTarget(std::int32_t target);
    void setStoneName(std::string const &name);
    std::string const &getStoneName() const;
    std::int32_t       getStoneTarget() const;

    std::pair<std::int32_t, std::int32_t> getDirection(std::int32_t) const;

    std::string const getNameForIdStone(std::int32_t id) const;

    std::array<std::int32_t, 6> getInventory() const;

    void         setPlayerId(std::int32_t);
    std::int32_t getPlayerId() const;

    std::array<std::int32_t, 6> const getCurCase() const;

    std::int32_t getTargetId() const;
    std::pair<std::int32_t, std::int32_t> getTargetDir() const;
    void setTargetDir(std::int32_t x, std::int32_t y);
    void setTargetId(std::int32_t id);

  private:
    std::map<std::string, std::int32_t>              m_inventory;
    std::vector<std::map<std::string, std::int32_t>> m_look;

    std::int32_t m_level;

    std::int32_t m_foodTarget;
    std::int32_t m_stoneTarget;
    std::string  m_stoneName;

    NetworkManager &m_network;

    std::int32_t m_targetId;
    std::pair<std::int32_t, std::int32_t> m_targetDir;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif

#endif // !PLAYERINFO_HPP_
