#ifndef INPUT_HPP
#define INPUT_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <input/keyCodes.hpp>

namespace FuraiEngine {
    class Input {
    private:
        static GLFWwindow* s_Window;

    public:
        static void Init(GLFWwindow* window);

        // ★ int から FuraiEngine::Key に変更
        static bool IsKeyPressed(Key keycode);
        
        // ★ 同様にコントローラーも変更
        static bool IsGamepadButtonPressed(GamepadButton button);
        static float GetGamepadAxis(GamepadAxis axis);
    };
}

#endif // INPUT_HPP