#include "zappy_ai_stdafx.hpp"

namespace zappy
{
  Model::Model(std::vector<glm::vec3> const &    vertices,
               std::vector<std::uint32_t> const &indices)
      : m_vertices(vertices), m_indices(indices)
  {
  }

  Model::Model(std::vector<glm::vec3> &&    vertices,
               std::vector<std::uint32_t> &&indices)
      : m_vertices(std::move(vertices)), m_indices(std::move(indices))
  {
  }

  Model::Model(Model const &that)
      : m_vertices(that.m_vertices), m_indices(that.m_indices)
  {
  }

  Model::Model(Model &&that)
      : m_vertices(std::move(that.m_vertices)),
        m_indices(std::move(that.m_indices))
  {
  }

  Model::~Model()
  {
  }

  std::vector<glm::vec3> const &Model::vertices() const
  {
    return (m_vertices);
  }

  std::vector<std::uint32_t> const &Model::indices() const
  {
    return (m_indices);
  }

  glm::vec3 const &Model::position() const
  {
    return (m_position);
  }

  glm::vec3 const &Model::scale() const
  {
    return (m_scale);
  }

  glm::quat const &Model::rotation() const
  {
    return (m_rotation);
  }

  glm::mat4 const &Model::fullTransform() const
  {
    if (m_fullTransformIsUpToDate == false)
      {
	m_fullTransform = glm::translate(
	    glm::rotate(glm::scale(glm::mat4(), m_scale), m_rotation),
	    m_position);
	m_fullTransformIsUpToDate = true;
      }
    return (m_fullTransform);
  }

  void Model::setPosition(double x, double y, double z)
  {
    this->setPosition(glm::vec3(x, y, z));
  }

  void Model::setPosition(glm::vec3 const &position)
  {
    m_position = position;
    m_fullTransformIsUpToDate = false;
  }

  void Model::setScale(double x, double y, double z)
  {
    this->setScale(glm::vec3(x, y, z));
  }

  void Model::setScale(glm::vec3 const &scale)
  {
    m_scale = scale;
    m_fullTransformIsUpToDate = false;
  }

  void Model::setRotation(glm::quat const &rotation)
  {
    m_rotation = rotation;
    m_fullTransformIsUpToDate = false;
  }

  void Model::setFullTransform(glm::mat4 const &fullTransform)
  {
    m_fullTransform = fullTransform;
    this->updateDataFromFullTransform();
    m_fullTransformIsUpToDate = true;
  }

  void Model::translate(double x, double y, double z)
  {
    this->translate(glm::vec3(x, y, z));
  }

  void Model::translate(glm::vec3 const &translation)
  {
    m_position += translation;
    m_fullTransformIsUpToDate = false;
  }

  void Model::scale(double x, double y, double z)
  {
    this->scale(glm::vec3(x, y, z));
  }

  void Model::scale(glm::vec3 const &scale)
  {
    m_scale = scale;
    m_fullTransformIsUpToDate = false;
  }

  void Model::rotate(glm::quat const &rotation)
  {
    m_rotation = rotation;
    m_fullTransformIsUpToDate = false;
  }

  void Model::applyTransform(glm::mat4 const &transform)
  {
    m_fullTransform = transform * m_fullTransform;
    this->updateDataFromFullTransform();
    m_fullTransformIsUpToDate = true;
  }

  void Model::updateDataFromFullTransform()
  {
    glm::mat4 tmp = m_fullTransform;
    m_position = glm::vec3(tmp[3]);
    m_scale.x = glm::vec3(tmp[0]).length();
    m_scale.y = glm::vec3(tmp[1]).length();
    m_scale.z = glm::vec3(tmp[2]).length();
    tmp[0] / m_scale.x;
    tmp[1] / m_scale.y;
    tmp[2] / m_scale.z;
    tmp[3] = glm::vec4(0.0, 0.0, 0.0, 1.0);

    m_rotation = glm::gtc::quat_cast(tmp);

    // TODO: check the results of this function
  }
}