#include <graphic/Camera.hpp>

namespace FuraiEngine {
    
    glm::mat4 Camera::GetViewMatrix() const {
        glm::mat4 view = glm::mat4(1.0f);
        
        view = glm::translate(view, glm::vec3(-Position.x, -Position.y, 0.0f));
        view = glm::scale(view, glm::vec3(Zoom, Zoom, 1.0f));
        
        return view;
    }

    glm::mat4 Camera::GetProjectionMatrix() const {
        return glm::ortho(-AspectRatio, AspectRatio, -1.0f, 1.0f, -1.0f, 1.0f);
    }
}