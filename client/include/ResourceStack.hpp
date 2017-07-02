#ifndef ZAPPY_RESOURCESTACK_HPP_
#define ZAPPY_RESOURCESTACK_HPP_

#include <cstdint>
#include <array>
#include "Mesh.hpp"
#include "Camera.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif // !__clang__

namespace zappy
{
  class Window;

  class ResourceStack
  {
  public:
    ResourceStack();
    ResourceStack(ResourceStack const &);
    ResourceStack(ResourceStack &&);
    ~ResourceStack();

    ResourceStack &operator=(ResourceStack const &);
    ResourceStack &operator=(ResourceStack &&);

    void addResource(std::size_t n = 1);
    void removeResource(std::size_t n = 1);
    void setResource(std::size_t n = 1);
    std::size_t getResourceNumber() const;

    void setColor(glm::vec4 const &color);

    glm::vec3 const &position() const;
    void setPosition(glm::vec3 const &position);

    void renderOn(Window &win, Camera const &camera) const;

  private:
    glm::vec3    m_position;
    std::size_t  m_count;
    mutable Mesh m_cube;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !ZAPPY_RESOURCESTACK_HPP_
