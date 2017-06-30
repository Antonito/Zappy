#ifndef ZAPPY_CAMERA_HPP_
#define ZAPPY_CAMERA_HPP_

#include <glm/glm.hpp>

namespace zappy
{
  class Camera
  {
  public:
    Camera() = delete;
    explicit Camera(glm::vec3 const &pos, float fov, float aspect, float zNear,
                    float xFar);
    Camera(Camera const &that);
    Camera(Camera &&that);
    ~Camera();

    Camera &operator=(Camera const &that);
    Camera &operator=(Camera &&that);

    glm::mat4        getViewProjection() const;
    glm::mat4 const &getPerspective() const;
    glm::mat4        getModelView() const;
    void setFov(float fov);

    glm::vec3 const &position() const;
    glm::vec2 const &rotation() const;

    void translate(glm::vec3 const &);
    void rotate(float x, float y);

    void setPosition(glm::vec3 const &position);
    void setRotation(float x, float y);
    void reset();

    void moveForward(float move);
    void moveSide(float move);
    void moveUp(float move);

    void updatePosition();

  private:
    void updateForward();

    constexpr static float m_maxSpeed = 0.1;

    glm::mat4 m_perspective;
    glm::vec3 m_forward;
    glm::vec3 m_position;
    glm::vec2 m_rotation;
    glm::vec3 m_up;

    glm::vec3 m_speed;
    glm::vec3 m_tryMoving;

    float m_aspect;
    float m_fov;
    float m_zNear;
    float m_zFar;
  };
}

#endif // !ZAPPY_CAMERA_HPP_