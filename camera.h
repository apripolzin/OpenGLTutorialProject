#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Camera
{
public:
    Camera(const glm::vec3 &pos, float fov, float aspect, float znear, float zfar)
    {
        m_perspective = glm::perspective(fov, aspect, znear, zfar);
        m_position = pos;
        m_forward = glm::vec3(0,0,1);
        m_up = glm::vec3(0,1,0);
    }

    inline glm::mat4 getViewProjection() const
    {
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }

private:
    glm::mat4 m_perspective;
    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_up;
};

#endif // CAMERA_H
