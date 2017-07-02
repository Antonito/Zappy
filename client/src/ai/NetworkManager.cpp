#include "zappy_ai_stdafx.hpp"

namespace ai
{
  NetworkManager::NetworkManager(std::string const &machine,
                                 std::uint16_t      port)
      : m_sock(port, machine, false, network::ASocket::SocketType::BLOCKING),
        m_buffer("")
  {
    if (m_sock.openConnection() == false)
      {
	throw std::runtime_error("AI failed to connect to the server");
      }
  }

  void NetworkManager::send(std::string const &msg)
  {
    fd_set wfds;
    int    ret;
    int    sock = m_sock.getSocket();

    nope::log::Log(Debug) << "Sending: " << msg;

    for (;;)
      {
	do
	  {
	    FD_ZERO(&wfds);

	    FD_SET(sock, &wfds);
	    struct timeval tm;

	    tm.tv_usec = 0;
	    tm.tv_sec = 3;

	    ret = select(sock + 1, nullptr, &wfds, nullptr, &tm);
	  }
	while (ret == -1 && errno == EINTR);

	if (ret == -1)
	  {
	    throw std::runtime_error(
	        std::string("Failed to write to network: ") +
	        std::strerror(errno));
	  }

	if (ret == 0)
	  {
	    throw std::runtime_error("Connection timed out");
	  }
	else if (FD_ISSET(sock, &wfds))
	  {
	    if (m_sock.send((msg + '\n').c_str(), msg.length() + 1) == false)
	      {
		throw std::runtime_error("Failed to write to network");
	      }
	    return;
	  }
      }
  }

  std::string NetworkManager::receive()
  {
    char    buf[4096];
    ssize_t len = 0;

    fd_set rds;
    int    ret;
    int    sock = m_sock.getSocket();

    while (m_buffer.find_first_of('\n') == std::string::npos)
      {
	do
	  {
	    FD_ZERO(&rds);

	    FD_SET(sock, &rds);
	    struct timeval tm;

	    tm.tv_usec = 0;
	    tm.tv_sec = 3;

	    ret = select(sock + 1, &rds, nullptr, nullptr, &tm);
	  }
	while (ret == -1 && errno == EINTR);

	if (ret == -1)
	  {
	    throw std::runtime_error(
	        std::string("Failed to read from network: ") +
	        std::strerror(errno));
	  }

	if (ret == 0)
	  {
	    throw std::runtime_error("Connection timed out");
	  }
	else if (ret && FD_ISSET(sock, &rds))
	  {
	    if (m_sock.rec(buf, sizeof(buf), &len) == false)
	      {
		throw std::runtime_error("Failed to read from network");
	      }

	    if (len == 0)
	      {
		throw std::runtime_error(
		    "Connection was closed by the server");
	      }

	    buf[len] = 0;
	    m_buffer += buf;
	  }
      }

    std::size_t pos = m_buffer.find_first_of('\n');

    std::string cmd = m_buffer.substr(0, pos);
    m_buffer = m_buffer.substr(pos + 1);

    nope::log::Log(Info) << "Received command: " << cmd;

    return (cmd);
  }
}
