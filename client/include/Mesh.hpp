#ifndef ZAPPY_MESH_HPP_
#define ZAPPY_MESH_HPP_

#include "Model.hpp"

namespace zappy
{
  class Mesh
  {
  public:
    Mesh() = delete;
    Mesh(Model const &);
    Mesh(Mesh const &);
    Mesh(Mesh &&);
    ~Mesh();

    Mesh &operator=(Mesh const &) = delete;
    Mesh &operator=(Mesh &&) = delete;

    glm::vec3 const &position() const;
    glm::vec3 const &scale() const;
    glm::quat const &rotation() const;

    glm::mat4 const &fullTransform() const;

    void setPosition(double x, double y, double z);
    void setPosition(glm::vec3 const &position);
    void setScale(double x, double y, double z);
    void setScale(glm::vec3 const &scale);
    void setRotation(glm::quat const &rotation);

    void setFullTransform(glm::mat4 const &fullTransform);

    void translate(double x, double y, double z);
    void translate(glm::vec3 const &translation);

    void scale(double x, double y, double z);
    void scale(glm::vec3 const &scale);

    void rotate(glm::quat const &rotation);

    void applyTransform(glm::mat4 const &tranform);

  private:
    void updateDataFromFullTransform();

    Model const &m_model;
    glm::vec3    m_position;
    glm::vec3    m_scale;
    glm::quat    m_rotation;
    glm::mat4    m_fullTransform;
    bool         m_fullTransformIsUpToDate;
  };
}

#endif // !ZAPPY_MESH_HPP_