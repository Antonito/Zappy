#ifndef ZAPPY_TILE_HPP_
#define ZAPPY_TILE_HPP_

#include <array>
#include "Window.hpp"
#include "Mesh.hpp"
#include "Resource.hpp"

namespace zappy
{
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

    std::array<std::size_t, Resource::NB_RESOURCE> m_resources;
    std::array<Mesh, Resource::NB_RESOURCE> m_resourcesMesh;
  };
}

#endif // !ZAPPY_TILE_HPP_
