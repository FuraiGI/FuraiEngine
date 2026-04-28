#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace FuraiEngine{
    class GUIComponent{
        public:
            void InitGUIComponent(GLFWwindow* _window);
            void BeginGUI();
            void EndGUI();

            ~GUIComponent();
    };

    class Graphics{
        private:
            GLFWwindow* _window;
        public:
            GUIComponent gui_comp;

            void CreateWindow(int width, int height, std::string title, GLFWmonitor *monitor, GLFWwindow *share);        
            void ViewPort(GLint x, GLint y, GLsizei width, GLsizei height);
            void ClearColor(float r, float g, float b, float a);
            void SwapBuffers();
            void PollEvents();
            int WindowShouldClose();

            Graphics(int width, int height, std::string title, GLFWmonitor *monitor, GLFWwindow *share);
            ~Graphics();
    };
};

#endif  // GRAPHICS_HPP