#ifndef ZAPPY_SHADER_HPP_
#define ZAPPY_SHADER_HPP_

#include <string>
#include <vector>
#include <memory>
#include <map>
#include <cstdint>
#include <GL/gl.h>
#include <glm/glm.hpp>
#include "Player.hpp"

namespace zappy
{
  class Shader
  {
  public:
    Shader() = delete;
    Shader(std::string const &path);
    Shader(Shader const &) = delete;
    Shader(Shader &&) = delete;
    ~Shader();

    Shader &operator=(Shader const &) = delete;
    Shader &operator=(Shader &&) = delete;

    void bind();

    void updateTransform(glm::mat4 const &transform);
    void updateShadowMat(glm::mat4 const &transform);
    void updateColor(glm::vec4 const &color);
    void updateLight(std::map<std::size_t, Player> const &players);

  private:
    static constexpr std::uint32_t numShader = 2;

    static GLuint loadShader(std::string const &filename, GLenum type);
    static void checkError(GLuint shader, GLuint flag, bool isProgram,
                           std::string const &errorMessage);

    struct Light
    {
      GLint position;
      GLint power;
      GLint direction;
    };

    enum
    {
      TRANSFORM_U,
      SHADOW_MAT_U,
      LIGHT_NB_U,
      COLOR_U,

      NB_UNIFORMS
    };

    GLuint m_program;
    GLuint m_shaders[numShader];
    std::array<Light, 16> m_lights;
    GLint m_uniforms[NB_UNIFORMS];
  };
}

#endif // !ZAPPY_SHADER_HPP_
