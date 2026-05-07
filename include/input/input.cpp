#include <input/input.hpp>

namespace FuraiEngine {    
    // 静的変数の実体定義
    GLFWwindow* Input::s_Window = nullptr;

    void Input::Init(GLFWwindow* window){
        s_Window = window;
    }

    bool Input::IsKeyPressed(Key keycode) {
        // enum class はそのままでは int として扱えないので、static_cast で int に戻して GLFW に渡す
        int state = glfwGetKey(s_Window, static_cast<int>(keycode));
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::IsGamepadButtonPressed(GamepadButton button) {
        GLFWgamepadstate state;
        if (glfwGetGamepadState(GLFW_JOYSTICK_1, &state)) {
            return state.buttons[static_cast<int>(button)] == GLFW_PRESS;
        }
        return false;
    }

    float Input::GetGamepadAxis(GamepadAxis axis) {
        GLFWgamepadstate state;
        if (glfwGetGamepadState(GLFW_JOYSTICK_1, &state)) {
            float value = state.axes[static_cast<int>(axis)];
            if (value > -0.1f && value < 0.1f) return 0.0f;
            return value;
        }
        return 0.0f;
    }
}