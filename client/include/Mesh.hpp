#ifndef ZAPPY_MESH_HPP_
#define ZAPPY_MESH_HPP_

#include <glm/glm.hpp>
#include <glm/gtx/quaternion.hpp>
#include "Model.hpp"

#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wpadded"
#endif // !__clang__

namespace zappy
{
  class Mesh
  {
  public:
    Mesh() = delete;
    Mesh(Model const &    model,
         glm::vec3 const &position = glm::vec3(0.0, 0.0, 0.0),
         glm::vec3 const &scale = glm::vec3(1.0, 1.0, 1.0),
         glm::quat const &rotation = glm::quat(glm::vec3(0.0, 0.0, 0.0)));
    Mesh(Mesh const &);
    Mesh(Mesh &&);
    virtual ~Mesh();

    Mesh &operator=(Mesh const &) = delete;
    Mesh &operator=(Mesh &&) = delete;

    Model const &model() const;

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

    Model const &     m_model;
    glm::vec3         m_position;
    glm::vec3         m_scale;
    glm::quat         m_rotation;
    mutable glm::mat4 m_fullTransform;
    mutable bool      m_fullTransformIsUpToDate;
  };
}

#if defined(__clang__)
#pragma clang diagnostic pop
#endif // !__clang__

#endif // !ZAPPY_MESH_HPP_
