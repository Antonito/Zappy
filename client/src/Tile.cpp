#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  constexpr std::array<glm::vec3, Resource::NB_RESOURCE>
                  Tile::m_resourcePosition;
  constexpr float Tile::m_tileScale;

  Tile::Tile() : m_cube(Model::fromObj("./models/cube.obj")), m_resources()
  {
    constexpr float coeff = 0.8f;
    float           r = static_cast<float>(std::rand()) /
               static_cast<float>(RAND_MAX) * coeff;
    float g = static_cast<float>(std::rand()) /
               static_cast<float>(RAND_MAX) * coeff;
    float b = static_cast<float>(std::rand()) /
               static_cast<float>(RAND_MAX) * coeff;
    m_cube.setColor(r, std::min(g + 0.7f, 1.0f), b);

    m_cube.scale(static_cast<double>(m_tileScale));

    for (std::size_t i = Resource::FOOD; i < Resource::NB_RESOURCE; ++i)
      {
	m_resources[i].setColor(
	    Resource::color(static_cast<Resource::Type>(i)));
      }
    this->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
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
    return (m_resources[type].getResourceNumber());
  }

  void Tile::renderOn(Window &win, Camera const &camera) const
  {
    win.draw(camera, m_cube);

    for (ResourceStack const &res : m_resources)
      {
	res.renderOn(win, camera);
      }
  }

  void Tile::setPosition(glm::vec3 const &position)
  {
    nope::log::Log(Debug) << "Setting a tile position in (" << position.x
                          << ", " << position.y << ", " << position.z << ")";
    m_cube.setPosition(position);
    for (std::size_t i = 0; i < Resource::NB_RESOURCE; ++i)
      {
	m_resources[i].setPosition(position +
	                           m_resourcePosition[i] * m_tileScale +
	                           glm::vec3(-0.5, 0.5, -0.5));
      }
  }

  void Tile::addResource(Resource::Type type, std::size_t n)
  {
    m_resources[type].addResource(n);
  }

  void Tile::removeResource(Resource::Type type, std::size_t n)
  {
    m_resources[type].removeResource(n);
  }

  void Tile::setResource(Resource::Type type, std::size_t n)
  {
    m_resources[type].setResource(n);
  }
}
