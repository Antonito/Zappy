#ifndef ZAPPY_MESSAGE_HPP_
#define ZAPPY_MESSAGE_HPP_

#include <cstdint>
#include <vector>
#include <string>

namespace ai
{
  struct Message
  {
    enum class Type
    {
      NONE = -1,
      COME,
      GO_AWAY,
      END_INCANT
    };

    Message();
    Message(std::string const &msg);
    Message(Message const &);
    Message(Message &&);
    ~Message();

    Message &operator=(Message const &);
    Message &operator=(Message &&);

    Type                     type;
    std::int32_t             id;
    std::vector<std::string> opt;
    std::int32_t             x;
    std::int32_t             y;
  };
}

#endif // !ZAPPY_MESSAGE_HPP_
