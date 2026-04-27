#include <furai.hpp>

namespace DebugMenu{
    void Run(float clear_color[4]){
        ImGui::Begin("Debug Menu");
        ImGui::Text("Hello Furai Engine!!");
        ImGui::ColorEdit4("BackEnd color", clear_color);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }
}

int main()
{
    Furai::Graphics graphics;

    graphics.CreateWindow(800, 600, "test-app", NULL, NULL);

    graphics.ViewPort(0, 0, 800, 600);

    float clear_color[4] = { 0.2f, 0.3f, 0.3f, 0.1f };

    while(!graphics.WindowShouldClose()){
        glfwPollEvents();

        glClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);
        glClear(GL_COLOR_BUFFER_BIT);

        graphics.gui_comp.BeginGUI();

        DebugMenu::Run(clear_color);

        graphics.gui_comp.EndGUI();

        graphics.SwapBuffers();
    }

    return 0;
}