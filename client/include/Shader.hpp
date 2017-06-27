#ifndef ZAPPY_SHADER_HPP_
#define ZAPPY_SHADER_HPP_

#include <string>
#include <GL/gl.h>

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

  private:
    static constexpr std::uint32_t numShader = 2;

    static GLuint loadShader(std::string const &filename, GLenum type);
    static void checkError(GLuint shader, GLuint flag, bool isProgram,
                           std::string const &errorMessage);

    GLuint m_program;
    GLuint m_shaders[numShader];
  };
}

#endif // !ZAPPY_SHADER_HPP_
