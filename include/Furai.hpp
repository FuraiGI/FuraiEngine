#ifndef FURAI_HPP
#define FURAI_HPP

#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

namespace Furai{
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
            void SwapBuffers();
            int WindowShouldClose();

            Graphics();
            ~Graphics();
    };
};

#endif // FURAI_HPP