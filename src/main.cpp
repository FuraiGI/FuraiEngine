#include <furai.hpp>
#include <iostream>

namespace DebugMenu{
    void DragFloatWithWheel(const char* label, float* v, float speed, float wheel_sensitivity) {
        ImGui::DragFloat(label, v, speed);
        
        if (ImGui::IsItemHovered()) {
            float wheel = ImGui::GetIO().MouseWheel;
            if (wheel != 0.0f) {
                *v += wheel * wheel_sensitivity;
            }
        }
    }

    void Run(float clear_color[4]){
        ImGui::Begin("Debug Menu");
        ImGui::Text("Hello Furai Engine!!");
        ImGui::ColorEdit4("BackEnd color", clear_color);
        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();
    }

    void Run_Transform(const char* window_name, FuraiEngine::Shape::Rectangle& myRect){
        ImGui::Begin(window_name);
        
        // 第3引数 = ドラッグ時のスピード
        // 第4引数 = ホイールを回したときの変化量
        DragFloatWithWheel("Position X", &myRect.x, 0.01f, 0.1f);
        DragFloatWithWheel("Position Y", &myRect.y, 0.01f, 0.1f);
        
        // 回転は少し大きめに動くようにする (1カリッで 5度 まわる)
        DragFloatWithWheel("Rotation", &myRect.angle, 1.0f, 5.0f);
        
        DragFloatWithWheel("Scale X", &myRect.scaleX, 0.01f, 0.1f);
        DragFloatWithWheel("Scale Y", &myRect.scaleY, 0.01f, 0.1f);
        
        ImGui::End();
    }
}

int main()
{
    FuraiEngine::Graphics graphics(1600, 900, "Furai Engine Test", nullptr, nullptr);
    
    FuraiEngine::Shader myShader(
        FuraiEngine::Paths::SHADER_BASIC_VERT,
        FuraiEngine::Paths::SHADER_BASIC_FRAG
    );

    FuraiEngine::Shape::Rectangle myRect(1.0f, 0.5f);
    FuraiEngine::Shape::Rectangle myRect2(1.0f, 0.5f);

    float clear_color[4] = { 0.2f, 0.3f, 0.3f, 1.0f };
    
    MAIN_LOOP(graphics){
        graphics.PollEvents();
        graphics.ClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);

        // UIのフレーム開始
        graphics.gui_comp.BeginGUI();

        // ここに好きなだけUIパネルを並べる
        DebugMenu::Run(clear_color);
        DebugMenu::Run_Transform("Transform Object_0", myRect);
        DebugMenu::Run_Transform("Transform Object_1", myRect2);

        // UIのフレーム終了
        graphics.gui_comp.EndGUI();

        myShader.Use(); 
        myShader.SetFloat("u_aspectRatio", graphics.GetAspectRatio());

        // 描画
        myRect.Draw(myShader);
        myRect2.Draw(myShader);

        graphics.SwapBuffers();
    }

    return 0;
}