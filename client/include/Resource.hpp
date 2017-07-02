#ifndef ZAPPY_RESOURCE_HPP_
#define ZAPPY_RESOURCE_HPP_

#include <array>
#include <glm/glm.hpp>
#include "Mesh.hpp"

namespace zappy
{
  class Resource
  {
  public:
    enum Type
    {
      FOOD,
      LINEMATE,
      DERAUMERE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME,

      NB_RESOURCE
    };

    static glm::vec4 color(Type t);
  };
}

#endif // !ZAPPY_RESOURCE_HPP_
