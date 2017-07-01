#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  ResourceStack::ResourceStack()
      : m_position(0, 0, 0), m_count(0),
        m_cube(Model::fromObj("./models/cube.obj"))
  {
    nope::log::Log(Debug) << "Constructing a resource stack";
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
    for (std::size_t i = 0; i < m_count; ++i)
      {
	m_cube.setPosition(m_position + glm::vec3(0, static_cast<float>(i) * 0.07f, 0));
	win.draw(camera, m_cube);
      }
  }
}
