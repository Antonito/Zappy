#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  glm::vec4 Resource::color(Resource::Type t)
  {
    glm::vec4 color;

    switch (t)
      {
      case FOOD:
	color = {130, 60, 30, 255};
	break;
      case LINEMATE:
	color = {0, 127, 255, 255};
	break;
      case DERAUMERE:
	color = {55, 170, 60, 255};
	break;
      case SIBUR:
	color = {255, 145, 0, 255};
	break;
      case MENDIANE:
	color = {255, 0, 0, 255};
	break;
      case PHIRAS:
	color = {255, 255, 0, 255};
	break;
      case THYSTAME:
	color = {240, 0, 255, 255};
	break;
      }
    color.r /= 255.0;
    color.g /= 255.0;
    color.b /= 255.0;
    color.a /= 255.0;
    return (color);
  }
}