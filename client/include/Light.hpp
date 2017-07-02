#ifndef ZAPPY_LIGHT_HPP_
#define ZAPPY_LIGHT_HPP_

#include <glm/glm.hpp>

namespace zappy
{
  struct Light
  {
    glm::vec3 position;
    float     intensity;
  };
}

#endif // !ZAPPY_LIGHT_HPP_