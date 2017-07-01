#ifndef ZAPPY_TILE_HPP_
#define ZAPPY_TILE_HPP_

#include <array>
#include "Mesh.hpp"
#include "Resource.hpp"
#include "ResourceStack.hpp"

namespace zappy
{
  class Window;

  class Tile
  {
  public:
    Tile();
    Tile(Tile const &);
    Tile(Tile &&);
    ~Tile();

    Tile &operator=(Tile const &);
    Tile &operator=(Tile &&);

    std::size_t operator[](Resource::Type r) const;

    void renderOn(Window &window, Camera const &camera) const;
    void setPosition(glm::vec3 const &position);

    void addResource(Resource::Type r, std::size_t n = 1);
    void removeResource(Resource::Type r, std::size_t n = 1);
    void setResource(Resource::Type r, std::size_t n);

  private:
    Mesh m_cube;

    constexpr static std::array<glm::vec3, Resource::NB_RESOURCE>
        m_resourcePosition = {
            {glm::vec3(0.85, 0.0, 0.45), glm::vec3(0.65, 0.0, 0.85),
             glm::vec3(0.85, 0.0, 0.85), glm::vec3(0.85, 0.0, 0.65),
             glm::vec3(0.85, 0.0, 0.25), glm::vec3(0.85, 0.0, 0.05),
             glm::vec3(0.65, 0.0, 0.05)}};
    constexpr static float m_tileScale = 0.97f;

    std::array<ResourceStack, Resource::NB_RESOURCE> m_resources;
  };
}

#endif // !ZAPPY_TILE_HPP_
