#include <core/Time.hpp>
#include <GLFW/glfw3.h>

namespace FuraiEngine {
    float Time::s_DeltaTime = 0.0f;
    float Time::s_LastFrameTime = 0.0f;

    void Time::Update() {
        float currentFrame = static_cast<float>(glfwGetTime());
        
        s_DeltaTime = currentFrame - s_LastFrameTime;
        
        s_LastFrameTime = currentFrame;
    }

    float Time::GetDeltaTime() {
        return s_DeltaTime;
    }
}