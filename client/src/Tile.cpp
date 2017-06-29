#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Tile::Tile() : m_cube(Model::fromObj("./models/cube.obj")), m_resources()
  {
    constexpr double coeff = 0.8;
    double           r = static_cast<double>(std::rand()) /
               static_cast<double>(RAND_MAX) * coeff;
    double g = static_cast<double>(std::rand()) /
               static_cast<double>(RAND_MAX) * coeff;
    double b = static_cast<double>(std::rand()) /
               static_cast<double>(RAND_MAX) * coeff;

    m_cube.setColor(r, std::min(g + 0.7, 1.0), b);

    constexpr float scale = 0.9;

    m_cube.scale(scale, scale, scale);

    for (std::size_t i = Resource::FOOD; i < Resource::NB_RESOURCE; ++i)
      {
	m_resources[i] = 0;
	m_resourcesMesh[i] = Resource::mesh(static_cast<Resource::Type>(i));
      }
  }

  Tile::Tile(Tile const &that)
      : m_cube(that.m_cube), m_resources(that.m_resources)
  {
  }

  Tile::Tile(Tile &&that)
      : m_cube(std::move(that.m_cube)),
        m_resources(std::move(that.m_resources))
  {
  }

  Tile::~Tile()
  {
  }

  Tile &Tile::operator=(Tile const &that)
  {
    if (this == &that)
      return (*this);
    m_cube = that.m_cube;
    return (*this);
  }

  Tile &Tile::operator=(Tile &&that)
  {
    if (this == &that)
      return (*this);
    m_cube = std::move(that.m_cube);
    return (*this);
  }

  std::size_t Tile::operator[](Resource::Type type) const
  {
    return (m_resources[type]);
  }

  void Tile::renderOn(Window &win, Camera const &camera) const
  {
    win.draw(camera, m_cube);

    for (std::size_t i = 0; i < Resource::NB_RESOURCE; ++i)
      {
	if (m_resources[i] > 0)
	  {
	    win.draw(camera, m_resourcesMesh[i]);
	  }
      }
  }

  void Tile::setPosition(glm::vec3 const &position)
  {
    m_cube.setPosition(position);
    for (std::size_t i = 0; i < Resource::NB_RESOURCE; ++i)
      {
	m_resourcesMesh[i].setPosition(position +
	                               glm::vec3(0, i / 2.0 + 1.0, 0));
      }
  }

  void Tile::addResource(Resource::Type type, std::size_t n)
  {
    m_resources[type] += n;
  }

  void Tile::removeResource(Resource::Type type, std::size_t n)
  {
    if (m_resources[type] < n)
      {
	throw std::logic_error(
	    "Trying to remove more resource than there are");
      }

    m_resources[type] -= n;
  }

    void Tile::setResource(Resource::Type type, std::size_t n)
  {
    m_resources[type] = n;
  }
}
