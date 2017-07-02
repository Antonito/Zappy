#ifndef ZAPPY_NETWORKMANAGER_HPP_
#define ZAPPY_NETWORKMANAGER_HPP_

#include <string>
#include "TCPSocket.hpp"
#include "Message.hpp"

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

    Message getMessage();

  private:
    bool isTeam(std::string const &message) const;

    std::queue<std::string> m_response;
    std::queue<Message>     m_message;
    network::TCPSocket      m_sock;
    std::string             m_buffer;
  };
}

#endif // !ZAPPY_NETWORKMANAGER_HPP_
