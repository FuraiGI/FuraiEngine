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

int main(){
    FuraiEngine::Graphics graphics(800, 600, "test-app", NULL, NULL);

    float clear_color[4] = { 0.2f, 0.3f, 0.3f, 0.1f };
    
    MAIN_LOOP(graphics){
        graphics.PollEvents();

        graphics.ClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);

        graphics.gui_comp.BeginGUI();

        DebugMenu::Run(clear_color);

        graphics.gui_comp.EndGUI();

        graphics.SwapBuffers();
    }

    return 0;
}