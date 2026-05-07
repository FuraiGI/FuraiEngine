#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <furai.hpp>

namespace FE = FuraiEngine;

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

    void Run_Transform(const char* window_name, FE::Shape::Rectangle& myRect){
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

#endif // DEBUG_HPP