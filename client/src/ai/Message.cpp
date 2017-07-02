#include "zappy_ai_stdafx.hpp"

namespace ai
{
  Message::Message()
      : type(Type::COME), id(0), opt(), x(0), y(0)
  {
  }

  Message::Message(std::string const &)
      : type(Type::COME), id(0), opt(), x(0), y(0)
  {
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
