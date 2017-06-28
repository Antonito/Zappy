#ifndef ZAPPY_MODEL_HPP_
#define ZAPPY_MODEL_HPP_

#include <vector>
#include <cstdint>
#include <string>
#include <array>
#include <glm/glm.hpp>
#include <GL/gl.h>
#include "IndicesElement.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif // !__clang__

namespace zappy
{
  class Model
  {
  public:
    Model() = delete;
    Model(std::vector<glm::vec3> const &vertices,
          std::vector<GLuint> const &indices);
    Model(std::vector<glm::vec3> &&vertices,
          std::vector<GLuint> &&indices);
    Model(Model const &);
    Model(Model &&);
    ~Model();

    Model &operator=(Model const &);
    Model &operator=(Model &&);

    static Model fromObj(std::string const &path);

    std::vector<glm::vec3> const &vertices() const;
    std::vector<glm::vec3> const &normals() const;
    std::vector<GLuint> const &indices() const;

    void render() const;

  private:
    void init();
    void calcNormals();

    enum BufferType
    {
      VERTEX_VB,
      NORMAL_VB,

      INDICES_VB,

      NB_BUFFER_TYPES
    };

    std::vector<glm::vec3> m_vertices;
    std::vector<glm::vec3> m_normals;
    std::vector<GLuint> m_indices;

    // Vertex Array Object
    GLuint m_vao;

    std::array<GLuint, NB_BUFFER_TYPES> m_vbos;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !ZAPPY_MODEL_HPP_
