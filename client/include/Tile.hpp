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

    std::size_t operator[](Resource r) const;

    void renderOn(Window &window, Camera const &camera) const;
    void setPosition(glm::vec3 const &position);

    void addResource(Resource r, std::size_t n = 1);
    void removeResource(Resource r, std::size_t n = 1);
  private:
    Mesh m_cube;

    constexpr static std::size_t nbResources =
        static_cast<std::size_t>(Resource::NB_RESOURCE);

    std::array<std::size_t, nbResources> m_resources;
  };
}

#endif // !ZAPPY_TILE_HPP_
