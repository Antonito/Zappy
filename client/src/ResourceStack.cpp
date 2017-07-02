#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  ResourceStack::ResourceStack()
      : m_position(0, 0, 0), m_count(0),
        m_cube(Model::fromObj("./models/cube.obj"))
  {
    m_cube.scale(0.05);
  }

  ResourceStack::ResourceStack(ResourceStack const &that)
      : m_position(that.m_position), m_count(that.m_count), m_cube(that.m_cube)
  {
  }

  ResourceStack::ResourceStack(ResourceStack &&that)
      : m_position(std::move(that.m_position)),
        m_count(std::move(that.m_count)), m_cube(std::move(that.m_cube))
  {
  }

  ResourceStack::~ResourceStack()
  {
  }

  ResourceStack &ResourceStack::operator=(ResourceStack const &that)
  {
    if (this == &that)
      return (*this);
    m_position = that.m_position;
    m_count = that.m_count;
    m_cube = that.m_cube;
    return (*this);
  }

  ResourceStack &ResourceStack::operator=(ResourceStack &&that)
  {
    if (this == &that)
      return (*this);
    m_position = std::move(that.m_position);
    m_count = std::move(that.m_count);
    m_cube = std::move(that.m_cube);
    return (*this);
  }

  void ResourceStack::addResource(std::size_t n)
  {
    m_count += n;
  }

  void ResourceStack::removeResource(std::size_t n)
  {
    if (m_count < n)
      {
	throw std::invalid_argument(
	    "Cannot remove more resources than there are");
      }
    m_count -= n;
  }

  void ResourceStack::setResource(std::size_t n)
  {
    m_count = n;
  }

  std::size_t ResourceStack::getResourceNumber() const
  {
    return (m_count);
  }

  void ResourceStack::setColor(glm::vec4 const &color)
  {
    m_cube.setColor(color);
  }

  glm::vec3 const &ResourceStack::position() const
  {
    return (m_position);
  }

  void ResourceStack::setPosition(glm::vec3 const &position)
  {
    m_position = position;
  }

  void ResourceStack::renderOn(Window &win, Camera const &camera) const
  {
    float           dist = glm::length(m_position - camera.position());
    constexpr float g = 0.07f;

    if (m_count > 0 && glm::length(m_position - camera.position()) < 20.0f)
      {
	if (dist > 8.0f)
	  {
	    float s = m_cube.scale().y;
	    float c = (static_cast<float>(m_count) - 1.0f) * g + s;

	    m_cube.scale(1.0, static_cast<double>(c / s), 1.0);
	    m_cube.setPosition(m_position + glm::vec3(0, static_cast<double>(c) / 2.0 - 0.01, 0));
	    win.draw(camera, m_cube);
	    m_cube.scale(1.0, 1.0 / static_cast<double>(c * s), 1.0);
	  }
	else
	  {
	    for (std::size_t i = 0; i < m_count; ++i)
	      {
		m_cube.setPosition(m_position +
		                   glm::vec3(0, static_cast<float>(i) * g, 0));
		win.draw(camera, m_cube);
	      }
	  }
      }
  }
}
