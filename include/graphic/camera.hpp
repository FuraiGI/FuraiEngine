#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace FuraiEngine {
    class Camera {
    public:
        glm::vec2 Position;
        float Zoom;
        float AspectRatio;

        Camera(float aspectRatio) : Position(0.0f, 0.0f), Zoom(1.0f), AspectRatio(aspectRatio) {}

        glm::mat4 GetViewMatrix() const;

        glm::mat4 GetProjectionMatrix() const;
    };
}

#endif // CAMERA_HPP