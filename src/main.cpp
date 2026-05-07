#include <furai.hpp>
#include <iostream>

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

int main()
{
    FE::Graphics graphics(1600, 900, "Furai Engine Test", nullptr, nullptr);

    FE::Input::Init(graphics.GetWindow());
    
    FE::Shader myShader(
        FE::Paths::SHADER_BASIC_VERT,
        FE::Paths::SHADER_BASIC_FRAG
    );

    FE::Shape::Rectangle myRect(1.0f, 0.5f);

    // 1. 線 (細い四角形で作る)
    FE::Shape::Rectangle line(1.0f, 0.02f);
    line.y = 0.8f;

    // 2. 三角形 (3分割, X半径, Y半径)
    FE::Shape::Polygon triangle(3, 0.3f, 0.3f);
    triangle.x = -0.5f; triangle.y = 0.4f;

    // 3. 五角形 (5分割)
    FE::Shape::Polygon pentagon(5, 0.3f, 0.3f);
    pentagon.x = 0.0f; pentagon.y = 0.4f;

    // 4. 六角形 (6分割)
    FE::Shape::Polygon hexagon(6, 0.3f, 0.3f);
    hexagon.x = 0.5f; hexagon.y = 0.4f;

    // 5. 七角形 (7分割)
    FE::Shape::Polygon heptagon(7, 0.3f, 0.3f);
    heptagon.x = -0.5f; heptagon.y = -0.4f;

    // 6. 円 (36分割すれば、人間には円に見える)
    FE::Shape::Polygon circle(36, 0.3f, 0.3f);
    circle.x = 0.0f; circle.y = -0.4f;

    // 7. 楕円 (36分割 ＋ XとYの半径を変える)
    FE::Shape::Polygon ellipse(36, 0.4f, 0.2f);
    ellipse.x = 0.5f; ellipse.y = -0.4f;

    float clear_color[4] = { 0.2f, 0.3f, 0.3f, 1.0f };
    float moveSpeed = 0.0025f;
    
    MAIN_LOOP(graphics){
        graphics.PollEvents();
        graphics.ClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);

        graphics.camera.AspectRatio = graphics.GetAspectRatio();

        if (FE::Input::IsKeyPressed(FE::Key::Escape)) {
            graphics.CloseWindow();
        }
        if (FE::Input::IsKeyPressed(FE::Key::W)) myRect.y += moveSpeed;
        if (FE::Input::IsKeyPressed(FE::Key::S)) myRect.y -= moveSpeed;
        if (FE::Input::IsKeyPressed(FE::Key::A)) myRect.x -= moveSpeed;
        if (FE::Input::IsKeyPressed(FE::Key::D)) myRect.x += moveSpeed;

        graphics.gui_comp.BeginGUI();
            DebugMenu::Run(clear_color);
            DebugMenu::Run_Transform("Transform Object_0", myRect);
        graphics.gui_comp.EndGUI();

        myShader.Use();
        myShader.SetMat4("u_view", graphics.camera.GetViewMatrix());
        myShader.SetMat4("u_projection", graphics.camera.GetProjectionMatrix());

        // 描画
        myRect.Draw(myShader);
        line.Draw(myShader);
        triangle.Draw(myShader);
        pentagon.Draw(myShader);
        hexagon.Draw(myShader);
        heptagon.Draw(myShader);
        circle.Draw(myShader);
        ellipse.Draw(myShader);

        graphics.SwapBuffers();
    }

    return 0;
}