#include "zappy_ai_stdafx.hpp"
#include <cstring>

namespace zappy
{
  Shader::Shader(std::string const &path)
      : m_program(0), m_shaders(), m_lights(), m_uniforms()
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
    glBindAttribLocation(m_program, 1, "normale");

    // Link the program
    glLinkProgram(m_program);
    checkError(m_program, GL_LINK_STATUS, true,
               std::string("Shader program linking failed (") + path + ')');

    // Validate the program
    glValidateProgram(m_program);
    checkError(m_program, GL_VALIDATE_STATUS, true,
               std::string("Shader program is invalid (") + path + ')');

    m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");
    m_uniforms[SHADOW_MAT_U] = glGetUniformLocation(m_program, "shadow_mat");
    m_uniforms[LIGHT_NB_U] = glGetUniformLocation(m_program, "nbLights");
    m_uniforms[COLOR_U] = glGetUniformLocation(m_program, "color");

    for (std::size_t i = 0; i < m_lights.size(); ++i)
      {
	std::stringstream ss;

	ss << "light" << i;
	m_lights[i].position =
	    glGetUniformLocation(m_program, (ss.str() + ".position").c_str());
	m_lights[i].power =
	    glGetUniformLocation(m_program, (ss.str() + ".power").c_str());
	m_lights[i].direction =
	    glGetUniformLocation(m_program, (ss.str() + ".direction").c_str());
      }
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
    glUseProgram(m_program);
  }

  void Shader::updateTransform(glm::mat4 const &transform)
  {
    glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &transform[0][0]);
  }

  void Shader::updateShadowMat(glm::mat4 const &transform)
  {
    glUniformMatrix4fv(m_uniforms[SHADOW_MAT_U], 1, GL_FALSE,
                       &transform[0][0]);
  }

  void Shader::updateColor(glm::vec4 const &color)
  {
    glUniform4f(m_uniforms[COLOR_U], color.r, color.g, color.b, color.a);
  }

  void Shader::updateLight(std::map<std::size_t, Player> const &players)
  {
    std::vector<float> values;
    std::size_t        i = 0;
    int count = 0;

    std::array<glm::vec3, 4> norms = {{glm::vec3(0, 0, 1), glm::vec3(-1, 0, 0),
                                       glm::vec3(0, 0, -1),
                                       glm::vec3(1, 0, 0)}};

    for (std::pair<std::size_t, Player> const &player_ : players)
      {
	Player const &player = player_.second;

	std::size_t         power = player.level();
	Player::Orientation orientation = player.orientation();
	std::size_t         dir = static_cast<std::size_t>(orientation) - 1;
	glm::vec3 const &   pos =
	    player.position() + glm::vec3(0.0, 0.3, 0.0) + 0.1f * norms[dir];

	if (player.isLightUpToDate(power, dir, pos) == false)
	  {
	    glUniform3f(m_lights[i].position, pos.x, pos.y, pos.z);
	    glUniform1f(m_lights[i].power,
	                static_cast<float>(power) * 2.0f + 0.5f);
	    glUniform3f(m_lights[i].direction, norms[dir].x, norms[dir].y,
	                norms[dir].z);
	  }
	++i;
	count++;
      }

    glUniform1f(m_uniforms[LIGHT_NB_U], static_cast<float>(count));

    for (; i < m_lights.size(); ++i)
      {
	glUniform3f(m_lights[i].position, 0, 0, 0);
	glUniform1f(m_lights[i].power, 0);
	glUniform3f(m_lights[i].direction, 0, 0, 0);
      }
  }

  GLuint Shader::loadShader(std::string const &filename, GLenum type)
  {
    // Open the file
    std::ifstream fs(filename.c_str());

    if (fs.is_open() == false)
      {
	throw std::runtime_error(std::string("Cannot open ") + filename);
      }

    // Get is as a string via a stringstream
    std::stringstream ss;
    ss << fs.rdbuf();

    GLuint shader = glCreateShader(type);

    if (shader == 0)
      {
	throw std::logic_error(std::string("Failed to create the shader (") +
	                       filename + ')');
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
      }
  }
}
