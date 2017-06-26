#ifndef ZAPPY_MODEL_HPP_
#define ZAPPY_MODEL_HPP_

#include <vector>
#include <cstdint>
#include <glm/glm.hpp>

namespace zappy
{
  class Model
  {
  public:
    Model() = delete;
    Model(std::vector<glm::vec3> const &    vertices,
          std::vector<std::uint32_t> const &indices);
    Model(std::vector<glm::vec3> &&    vertices,
          std::vector<std::uint32_t> &&indices);
    Model(Model const &);
    Model(Model &&);
    ~Model();

    Model &operator=(Model const &) = delete;
    Model &operator=(Model &&) = delete;

    std::vector<glm::vec3> const &vertices() const;
    std::vector<std::uint32_t> const &indices() const;

  private:
    std::vector<glm::vec3>     m_vertices;
    std::vector<std::uint32_t> m_indices;
  };
}

#endif // !ZAPPY_MODEL_HPP_