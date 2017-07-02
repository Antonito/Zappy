#ifndef ZAPPY_NETWORKMANAGER_HPP_
#define ZAPPY_NETWORKMANAGER_HPP_

#include <string>

namespace ai
{
  class NetworkManager
  {
  public:
    NetworkManager() = delete;
    NetworkManager(std::string const &machine, std::uint16_t port);
    NetworkManager(NetworkManager const &) = delete;
    NetworkManager(NetworkManager &&) = delete;

    NetworkManager &operator=(NetworkManager const &) = delete;
    NetworkManager &operator=(NetworkManager &&) = delete;

    void send(std::string const &message);
    std::string receive();

  private:
  };
}

#endif // !ZAPPY_NETWORKMANAGER_HPP_
