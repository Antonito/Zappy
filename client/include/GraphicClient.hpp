#ifndef ZAPPY_GRAPHICCLIENT_HPP_
#define ZAPPY_GRAPHICCLIENT_HPP_

#include <SFML/Graphics.hpp>

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
    void askMapSize() const;
    void askTileContent(std::size_t x, std::size_t y) const;
    void askMapContent() const;
    void askTeamNames() const;
    void askPlayerPosition(std::size_t playerId) const;
    void askPlayerLevel(std::size_t playerId) const;
    void askPlayerInventory(std::size_t playerId) const;
    void askTimeUnit() const;
    void askTimeUnitModification(std::size_t unit) const;

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

#endif // !ZAPPY_GRAPHICCLIENT_HPP_