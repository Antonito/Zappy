#ifndef ZAPPY_TEAM_HPP_
#define ZAPPY_TEAM_HPP_

#include <string>
#include <glm/glm.hpp>

namespace zappy
{
  struct Team
  {
    Team();

    std::string name;
    glm::vec4   color;
  };
}

#endif // !ZAPPY_TEAM_HPP_
