#include "zappy_ai_stdafx.hpp"
#include <glm/gtx/rotate_vector.hpp>

namespace zappy
{
  Camera::Camera(glm::vec3 const &pos, float fov, float aspect, float zNear,
                 float zFar)
      : m_perspective(glm::perspective(fov * static_cast<float>(M_PI) / 180.f,
                                       aspect, zNear, zFar)),
        m_forward(0, 0, -1), m_position(pos), m_rotation(0, 0), m_up(0, 1, 0),
        m_speed(0, 0, 0), m_tryMoving(0, 0, 0), m_aspect(aspect),
        m_fov(fov * static_cast<float>(M_PI) / 180.f), m_zNear(zNear),
        m_zFar(zFar)
  {
  }

  Camera::Camera(Camera const &that)
      : m_perspective(that.m_perspective), m_forward(that.m_forward),
        m_position(that.m_position), m_rotation(that.m_rotation),
        m_up(that.m_up), m_speed(that.m_speed), m_tryMoving(that.m_tryMoving), m_aspect(that.m_aspect), m_fov(that.m_fov),
        m_zNear(that.m_zNear), m_zFar(that.m_zFar)
  {
  }

  Camera::Camera(Camera &&that)
      : m_perspective(std::move(that.m_perspective)),
        m_forward(std::move(that.m_forward)),
        m_position(std::move(that.m_position)),
        m_rotation(std::move(that.m_rotation)), m_up(std::move(that.m_up)),
	m_speed(std::move(that.m_speed)), m_tryMoving(std::move(that.m_tryMoving)),
        m_aspect(std::move(that.m_aspect)), m_fov(std::move(that.m_fov)),
        m_zNear(std::move(that.m_zNear)), m_zFar(std::move(that.m_zFar))
  {
  }

  Camera::~Camera()
  {
  }

  Camera &Camera::operator=(Camera const &that)
  {
    if (this == &that)
      return (*this);
    m_perspective = that.m_perspective;
    m_forward = that.m_forward;
    m_position = that.m_position;
    m_rotation = that.m_rotation;
    m_up = that.m_up;
    m_speed = that.m_speed;
    m_tryMoving = that.m_tryMoving;
    m_aspect = that.m_aspect;
    m_fov = that.m_fov;
    m_zNear = that.m_zNear;
    m_zFar = that.m_zFar;
    return (*this);
  }

  Camera &Camera::operator=(Camera &&that)
  {
    if (this == &that)
      return (*this);
    m_perspective = std::move(that.m_perspective);
    m_forward = std::move(that.m_forward);
    m_position = std::move(that.m_position);
    m_rotation = std::move(that.m_rotation);
    m_up = std::move(that.m_up);
    m_speed = std::move(that.m_speed);
    m_tryMoving = std::move(that.m_tryMoving);
    m_aspect = std::move(that.m_aspect);
    m_fov = std::move(that.m_fov);
    m_zNear = std::move(that.m_zNear);
    m_zFar = std::move(that.m_zFar);
    return (*this);
  }

  glm::mat4 Camera::getViewProjection() const
  {
    return (m_perspective *
            glm::lookAt(m_position, m_position + m_forward, m_up));
  }

  glm::mat4 const &Camera::getPerspective() const
  {
    return (m_perspective);
  }

  glm::mat4 Camera::getModelView() const
  {
    return (glm::lookAt(m_position, m_position + m_forward, m_up));
  }

  void Camera::setFov(float fov)
  {
    m_fov = fov * static_cast<float>(M_PI) / 180.f;
    m_perspective = glm::perspective(m_fov, m_aspect, m_zNear, m_zFar);
  }

  glm::vec3 const &Camera::position() const
  {
    return (m_position);
  }

  glm::vec2 const &Camera::rotation() const
  {
    return (m_rotation);
  }

  void Camera::translate(glm::vec3 const &translation)
  {
    m_position += translation;
  }

  void Camera::rotate(float x, float y)
  {
    m_rotation += glm::vec2(x, y);
    this->updateForward();
  }

  void Camera::setPosition(glm::vec3 const &position)
  {
    m_position = position;
  }

  void Camera::setRotation(float x, float y)
  {
    m_rotation = glm::vec2(x, y);
    this->updateForward();
  }

  void Camera::reset()
  {
    m_position = glm::vec3(0, 0, 0);
    m_rotation = glm::vec2(0, 0);
  }

  void Camera::updateForward()
  {
    if (m_rotation.y > 90.0f)
      {
	m_rotation.y = 89.9f;
      }
    else if (m_rotation.y < -90.0f)
      {
	m_rotation.y = -89.9f;
      }

    glm::vec3 dir = glm::rotate(
        glm::vec3(0, 0, -1), -m_rotation.y * static_cast<float>(M_PI) / 180.f,
        glm::vec3(1, 0, 0));
    dir = glm::rotate(dir, -m_rotation.x * static_cast<float>(M_PI) / 180.f,
                      glm::vec3(0, 1, 0));

    m_forward = glm::normalize(dir);
  }

  void Camera::moveForward(float move)
  {
    m_tryMoving.x += move;
  }

  void Camera::moveSide(float move)
  {
    m_tryMoving.y += move;
  }

  void Camera::moveUp(float move)
  {
    m_tryMoving.z += move;
  }

  void Camera::updatePosition()
  {
    constexpr float alpha = 0.1f;

    glm::vec3 forward = m_forward;
    glm::vec3 right = glm::cross(m_forward, m_up);
    glm::vec3 up = glm::cross(forward, right);
    glm::vec3 total =
        forward * m_tryMoving.x + right * m_tryMoving.y + up * m_tryMoving.z;

    m_speed = alpha * total + (1 - alpha) * m_speed;
    this->translate(m_speed);
  }
}
