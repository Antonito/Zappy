#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Mesh::Mesh(Model const &model, glm::vec3 const &position,
             glm::vec3 const &scale, glm::quat const &rotation)
      : m_model(&model), m_position(position), m_scale(scale),
        m_rotation(rotation), m_fullTransform(),
        m_fullTransformIsUpToDate(false), m_color(1.0, 1.0, 1.0, 1.0)
  {
  }

  Mesh::Mesh(Mesh const &that)
      : m_model(that.m_model), m_position(that.m_position),
        m_scale(that.m_scale), m_rotation(that.m_rotation),
        m_fullTransform(that.m_fullTransform),
        m_fullTransformIsUpToDate(that.m_fullTransformIsUpToDate),
        m_color(that.m_color)
  {
  }

  Mesh::Mesh(Mesh &&that)
      : m_model(std::move(that.m_model)),
        m_position(std::move(that.m_position)),
        m_scale(std::move(that.m_scale)),
        m_rotation(std::move(that.m_rotation)),
        m_fullTransform(std::move(that.m_fullTransform)),
        m_fullTransformIsUpToDate(std::move(that.m_fullTransformIsUpToDate)),
        m_color(std::move(that.m_color))
  {
  }

  Mesh::~Mesh()
  {
  }

  Mesh &Mesh::operator=(Mesh const &that)
  {
    if (this == &that)
      return (*this);
    m_model = that.m_model;
    m_position = that.m_position;
    m_scale = that.m_scale;
    m_rotation = that.m_rotation;
    m_fullTransform = that.m_fullTransform;
    m_fullTransformIsUpToDate = that.m_fullTransformIsUpToDate;
    m_color = that.m_color;
    return (*this);
  }

  Mesh &Mesh::operator=(Mesh &&that)
  {
    if (this == &that)
      return (*this);
    m_model = std::move(that.m_model);
    m_position = std::move(that.m_position);
    m_scale = std::move(that.m_scale);
    m_rotation = std::move(that.m_rotation);
    m_fullTransform = std::move(that.m_fullTransform);
    m_fullTransformIsUpToDate = std::move(that.m_fullTransformIsUpToDate);
    m_color = std::move(that.m_color);
    return (*this);
  }

  Model const &Mesh::model() const
  {
    return (*m_model);
  }

  glm::vec3 const &Mesh::position() const
  {
    return (m_position);
  }

  glm::vec3 const &Mesh::scale() const
  {
    return (m_scale);
  }

  glm::quat const &Mesh::rotation() const
  {
    return (m_rotation);
  }

  glm::mat4 const &Mesh::fullTransform() const
  {
    if (m_fullTransformIsUpToDate == false)
      {
	m_fullTransform = glm::translate(
	    glm::scale(glm::mat4_cast(m_rotation), m_scale), m_position);
	m_fullTransformIsUpToDate = true;
      }
    return (m_fullTransform);
  }

  glm::vec4 const &Mesh::color() const
  {
    return (m_color);
  }

  void Mesh::setPosition(double x, double y, double z)
  {
    this->setPosition(glm::vec3(x, y, z));
  }

  void Mesh::setPosition(glm::vec3 const &position)
  {
    m_position = position;
    m_fullTransformIsUpToDate = false;
  }

  void Mesh::setScale(double x, double y, double z)
  {
    this->setScale(glm::vec3(x, y, z));
  }

  void Mesh::setScale(glm::vec3 const &scale)
  {
    m_scale = scale;
    m_fullTransformIsUpToDate = false;
  }

  void Mesh::setRotation(glm::quat const &rotation)
  {
    m_rotation = rotation;
    m_fullTransformIsUpToDate = false;
  }

  void Mesh::setFullTransform(glm::mat4 const &fullTransform)
  {
    m_fullTransform = fullTransform;
    this->updateDataFromFullTransform();
    m_fullTransformIsUpToDate = true;
  }

  void Mesh::setColor(glm::vec4 const &color)
  {
    m_color = color;
  }

  void Mesh::setColor(float r, float g, float b, float a)
  {
    m_color = glm::vec4(r, g, b, a);
  }

  void Mesh::translate(double x, double y, double z)
  {
    this->translate(glm::vec3(x, y, z));
  }

  void Mesh::translate(glm::vec3 const &translation)
  {
    m_position += translation;
    m_fullTransformIsUpToDate = false;
  }

  void Mesh::scale(double x, double y, double z)
  {
    this->scale(glm::vec3(x, y, z));
  }

  void Mesh::scale(glm::vec3 const &scale)
  {
    m_scale = scale;
    m_fullTransformIsUpToDate = false;
  }

  void Mesh::rotate(glm::quat const &rotation)
  {
    m_rotation = rotation;
    m_fullTransformIsUpToDate = false;
  }

  void Mesh::applyTransform(glm::mat4 const &transform)
  {
    m_fullTransform = transform * m_fullTransform;
    this->updateDataFromFullTransform();
    m_fullTransformIsUpToDate = true;
  }

  void Mesh::updateDataFromFullTransform()
  {
    glm::mat4 tmp = m_fullTransform;
    m_position = glm::vec3(tmp[3]);
    m_scale.x = glm::length(glm::vec3(tmp[0]));
    m_scale.y = glm::length(glm::vec3(tmp[1]));
    m_scale.z = glm::length(glm::vec3(tmp[2]));
    tmp[0] / m_scale.x;
    tmp[1] / m_scale.y;
    tmp[2] / m_scale.z;
    tmp[3] = glm::vec4(0.0, 0.0, 0.0, 1.0);

    m_rotation = glm::quat_cast(tmp);

    // TODO: check the results of this function
  }
}
