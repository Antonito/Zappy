#include "zappy_ai_stdafx.hpp"

namespace ai
{
  Message::Message() : type(Type::COME), id(0), opt(), x(0), y(0)
  {
  }

  Message::Message(std::string const &msg)
      : type(Type::COME), id(0), opt(), x(0), y(0)
  {

#ifdef DEBUG
    nope::log::LogMessage log = nope::log::Log(Debug);
#else
    nope::log::EmptyLogger &log = nope::log::Log(Debug);
#endif // !DEBUG

    log << "Parsing a message: \n";

    assert(msg[8] >= '0' && msg[8] <= '9');
    std::size_t n = static_cast<std::size_t>(msg[8] - '0');

    constexpr std::array<std::int32_t, 9> xCoord = {
        {0, 0, 1, 1, 1, 0, -1, -1, -1}};
    constexpr std::array<std::int32_t, 9> yCoord = {
        {0, 1, 1, 0, -1, -1, -1, 0, 1}};

    x = xCoord[n];
    y = yCoord[n];

    log << "\tMessage is coming from (" << x << ", " << y << ")\n";

    std::istringstream ss(msg.substr(18));

    std::string cmd;
    std::string arg;

    ss >> cmd;
    ss >> id;
    log << "\tType is " << cmd << '\n';
    log << "\tId is " << id << '\n';
    log << "\tArgs:";
    while (ss >> arg)
      {
	opt.push_back(arg);
	log << ' ' << arg;
      }
    log << '\n';

    if (cmd == "COME")
      {
	type = Type::COME;
      }
    else if (cmd == "GO_AWAY")
      {
	type = Type::GO_AWAY;
      }
    else if (cmd == "END_INCANT")
      {
	type = Type::END_INCANT;
      }
  }

  Message::Message(Message const &that)
      : type(that.type), id(that.id), opt(that.opt), x(that.x), y(that.y)
  {
  }

  Message::Message(Message &&that)
      : type(std::move(that.type)), id(std::move(that.id)),
        opt(std::move(that.opt)), x(std::move(that.x)), y(std::move(that.y))
  {
  }

  Message::~Message()
  {
  }

  Message &Message::operator=(Message const &that)
  {
    if (this == &that)
      return (*this);
    type = that.type;
    id = that.id;
    opt = that.opt;
    x = that.x;
    y = that.y;
    return (*this);
  }

  Message &Message::operator=(Message &&that)
  {
    if (this == &that)
      return (*this);
    type = std::move(that.type);
    id = std::move(that.id);
    opt = std::move(that.opt);
    x = std::move(that.x);
    y = std::move(that.y);
    return (*this);
  }
}
