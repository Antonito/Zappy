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
    Model(IndicesElement<glm::vec3> const &vertices,
          IndicesElement<glm::vec2> const &uv,
          IndicesElement<glm::vec3> const &normals);
    Model(IndicesElement<glm::vec3> &&vertices, IndicesElement<glm::vec2> &&uv,
          IndicesElement<glm::vec3> &&normals);
    Model(Model const &);
    Model(Model &&);
    ~Model();

    Model &operator=(Model const &);
    Model &operator=(Model &&);

    static Model fromObj(std::string const &path);

    IndicesElement<glm::vec3> const &vertices() const;
    IndicesElement<glm::vec2> const &uv() const;
    IndicesElement<glm::vec3> const &normals() const;

  private:
    void init();

    enum BufferType
    {
      VERTEX,
      VERTEX_IDX,
      UV,
      UV_IDX,
      NORMAL,
      NORMAL_IDX,

      NB_BUFFER
    };

    IndicesElement<glm::vec3> m_vertices;
    IndicesElement<glm::vec2> m_uv;
    IndicesElement<glm::vec3> m_normals;

    // Vertex Array Object
    GLuint m_vao;

    std::array<GLuint, NB_BUFFER> m_buffersId;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !ZAPPY_MODEL_HPP_
