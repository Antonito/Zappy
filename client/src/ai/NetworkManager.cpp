#include "zappy_ai_stdafx.hpp"

namespace ai
{
  NetworkManager::NetworkManager(std::string const &machine,
                                 std::uint16_t      port)
      : m_response(), m_message(), m_sock(port, machine, false, network::ASocket::SocketType::BLOCKING),
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
    if (m_response.size() > 0)
      {
	std::string message = m_response.back();

	m_response.pop();
	return (message);
      }

    bool        isMessage;
    std::string cmd;
    do
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

	cmd = m_buffer.substr(0, pos);
	m_buffer = m_buffer.substr(pos + 1);
	isMessage = false;
	if (cmd.substr(0, 8) == "message ")
	  {
	    isMessage = true;
	    if (this->isTeam(cmd))
	      {
		m_message.emplace(cmd);
	      }
	  }
      }
    while (isMessage);

    nope::log::Log(Info) << "Received command: " << cmd;

    return (cmd);
  }

  Message NetworkManager::getMessage()
  {
    if (m_message.size() > 0)
      {
	Message message = m_message.back();

	m_message.pop();
	return (message);
      }

    bool    isMessage;
    Message msg;
    do
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
	isMessage = true;
	if (cmd.substr(0, 8) != "message ")
	  {
	    isMessage = false;
	    m_response.push(cmd);
	  }
	else
	  {
	    if (this->isTeam(cmd))
	      {
		msg = Message(cmd);
	      }
	    else
	      {
		isMessage = false;
	      }
	  }
      }
    while (!isMessage);

    nope::log::Log(Info) << "Received message";

    return (msg);
  }

  bool NetworkManager::isTeam(std::string const &msg) const
  {
    if (msg.substr(0, 8) != "message ")
      {
	return (false);
      }

    if (msg.substr(11, 6) != "EmBsTf")
      {
	return (false);
      }
    return (true);
  }
}
