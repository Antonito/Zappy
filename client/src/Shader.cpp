#include "zappy_ai_stdafx.hpp"
#include <cstring>

namespace zappy
{
  Shader::Shader(std::string const &path) : m_program(0), m_shaders()
  {
    // Create the program
    m_program = glCreateProgram();

    // Load the shaders
    m_shaders[0] = loadShader(path + ".vs", GL_VERTEX_SHADER);
    m_shaders[1] = loadShader(path + ".fs", GL_FRAGMENT_SHADER);

    // Attach them to the program
    for (std::uint32_t i = 0; i < numShader; ++i)
      {
	glAttachShader(m_program, m_shaders[i]);
      }

    // Bind the differents attributes
    glBindAttribLocation(m_program, 0, "position");
    // glBindAttribLocation(m_program, 1, "textCoord");
    // glBindAttribLocation(m_program, 2, "normale");

    // Link the program
    glLinkProgram(m_program);
    checkError(m_program, GL_LINK_STATUS, true,
               std::string("Shader program linking failed (") + path + ')');

    // Validate the program
    glValidateProgram(m_program);
    checkError(m_program, GL_VALIDATE_STATUS, true,
               std::string("Shader program is invalid (") + path + ')');
  }

  Shader::~Shader()
  {
    // Detach and delete the shaders
    for (std::uint32_t i = 0; i < numShader; ++i)
      {
	glDetachShader(m_program, m_shaders[i]);
	glDeleteShader(m_shaders[i]);
      }

    // Delete the program
    glDeleteProgram(m_program);
  }

  void Shader::bind()
  {
  }

  GLuint Shader::loadShader(std::string const &filename, GLenum type)
  {
    // Open the file
    std::ifstream fs(filename.c_str());

    if (fs.is_open() == false)
      {
	throw std::system_error();
	// TODO: set a message: cannot open "filename"
      }

    // Get is as a string via a stringstream
    std::stringstream ss;
    ss << fs.rdbuf();

    GLuint shader = glCreateShader(type);

    if (shader == 0)
      {
	throw std::logic_error(std::string("Failed to create the shader (") +
	                       filename + ')');
	// TODO: set a better exception
      }

    std::string   source = ss.str();
    GLchar const *shaderSource = source.c_str();
    GLint         length = static_cast<GLint>(source.length());

    glShaderSource(shader, 1, &shaderSource, &length);
    glCompileShader(shader);

    checkError(shader, GL_COMPILE_STATUS, false,
               std::string("Shader compilation failed (") + filename + ')');

    return (shader);
  }

  void Shader::checkError(GLuint shader, GLuint flag, bool isProgram,
                          std::string const &errorMessage)
  {
    GLint  success = 0;
    GLchar error[1024] = {0};

    if (isProgram)
      {
	glGetProgramiv(shader, flag, &success);
      }
    else
      {
	glGetShaderiv(shader, flag, &success);
      }

    if (success == GL_FALSE)
      {
	if (isProgram)
	  {
	    glGetProgramInfoLog(shader, sizeof(error), nullptr, error);
	  }
	else
	  {
	    glGetShaderInfoLog(shader, sizeof(error), nullptr, error);
	  }

	throw std::logic_error(errorMessage + ": " + error);
	// TODO: set an adapted exception
      }
  }
}
