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

  std::size_t Tile::operator[](Resource r) const
  {
    return (m_resources[static_cast<std::size_t>(r)]);
  }

  void Tile::renderOn(Window &win, Camera const &camera) const
  {
    win.draw(camera, m_cube);
  }

  void Tile::setPosition(glm::vec3 const &position)
  {
    m_cube.setPosition(position);
  }

  void Tile::addResource(Resource r, std::size_t n)
  {
    m_resources[static_cast<std::size_t>(r)] += n;
  }

  void Tile::removeResource(Resource r, std::size_t n)
  {
    std::size_t _r = static_cast<std::size_t>(r);
    if (m_resources[_r] < n)
      {
	throw std::logic_error(
	    "Trying to remove more resource than there are");
      }
      
    m_resources[_r] -= n;
  }
}
