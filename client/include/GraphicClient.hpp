#ifndef ZAPPY_GRAPHICCLIENT_HPP_
#define ZAPPY_GRAPHICCLIENT_HPP_

#include <SFML/Graphics.hpp>
#include "GameMap.hpp"
#include "Player.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif // !__clang__

namespace zappy
{
  class GraphicClient
  {
  public:
    GraphicClient() = delete;
    GraphicClient(GraphicClient const &) = delete;
    explicit GraphicClient(unsigned int width, unsigned int height,
                           std::string const &windowName, std::uint16_t port,
                           std::string const &name,
                           std::string const &machine);
    GraphicClient(GraphicClient &&) = delete;
    ~GraphicClient();

    GraphicClient &operator=(GraphicClient const &) = delete;
    GraphicClient &operator=(GraphicClient &&) = delete;

    void launch();

  private:
    void sendCommand(std::string const &command);
    bool receiveCommand(std::string &command);

    //
    // Send command
    //
    void askMapSize();
    void askTileContent(std::size_t x, std::size_t y);
    void askMapContent();
    void askTeamNames();
    void askPlayerPosition(std::size_t playerId);
    void askPlayerLevel(std::size_t playerId);
    void askPlayerInventory(std::size_t playerId);
    void askTimeUnit();
    void askTimeUnitModification(std::size_t unit);

    //
    // Received command
    //
    void mapSize(std::string const &data);
    void mapContent(std::string const &data);
    void teamNames(std::string const &data);
    void newPlayer(std::string const &data);
    void playerPosition(std::string const &data);
    void playerLevel(std::string const &data);
    void playerInventory(std::string const &data);
    void ejected(std::string const &data);
    void broadcast(std::string const &data);
    void launchIncantation(std::string const &data);
    void endOfIncantation(std::string const &data);
    void layAnEgg(std::string const &data);
    void dropResource(std::string const &data);
    void takeResource(std::string const &data);
    void starved(std::string const &data);
    void eggLayed(std::string const &data);
    void eggHatching(std::string const &data);
    void playerConnectedForEgg(std::string const &data);
    void hatchedEggStarved(std::string const &data);
    void timeUnit(std::string const &data);
    void endOfGame(std::string const &data);
    void serverMessage(std::string const &data);
    void unknownCommand(std::string const &data);
    void badParameter(std::string const &data);

    // Command parsing methods
    static std::size_t parseInt(std::istringstream &is);
    static std::size_t parsePlayerId(std::istringstream &is);
    static Player::Orientation parseOrientation(std::istringstream &is);
    static std::string parseTeamName(std::istringstream &is);
    static std::string parseMessage(std::istringstream &is);

    // Window
    sf::RenderWindow m_win;

    // Basic infos
    std::uint16_t m_port;
    std::string   m_name;
    std::string   m_machine;

    // Game data
    GameMap             m_map;
    std::vector<Player> m_players;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !ZAPPY_GRAPHICCLIENT_HPP_
