#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Model::Model(std::vector<glm::vec3> const &    vertices,
               std::vector<std::uint32_t> const &indices)
      : m_vertices(vertices), m_indices(indices)
  {
  }

  Model::Model(std::vector<glm::vec3> &&    vertices,
               std::vector<std::uint32_t> &&indices)
      : m_vertices(std::move(vertices)), m_indices(std::move(indices))
  {
  }

  Model::Model(Model const &that)
      : m_vertices(that.m_vertices), m_indices(that.m_indices)
  {
  }

  Model::Model(Model &&that)
      : m_vertices(std::move(that.m_vertices)),
        m_indices(std::move(that.m_indices))
  {
  }

  Model::~Model()
  {
  }

  std::vector<glm::vec3> const &Model::vertices() const
  {
    return (m_vertices);
  }

  std::vector<std::uint32_t> const &Model::indices() const
  {
    return (m_indices);
  }

}
