#include <furai.hpp>

#include "debug.hpp"

namespace FE = FuraiEngine;

int main()
{
    FE::Graphics graphics(1600, 900, "Furai Engine Test", nullptr, nullptr);

    FE::Input::Init(graphics.GetWindow());
    
    FE::Shader myShader(
        FE::Paths::SHADER_BASIC_VERT,
        FE::Paths::SHADER_BASIC_FRAG
    );

    std::vector<std::unique_ptr<FE::Shape::Shape>> shapes;

    // 図形を作って箱にどんどん放り込む
    auto rect = std::make_unique<FE::Shape::Rectangle>(0.5f, 0.5f);
    rect->x = -0.5f;
    shapes.push_back(std::move(rect));

    auto circle = std::make_unique<FE::Shape::Polygon>(128, 0.3f, 0.3f);
    circle->x = 0.5f;
    shapes.push_back(std::move(circle));

    auto triangle = std::make_unique<FE::Shape::Polygon>(3, 0.3f, 0.3f);
    triangle->y = 0.5f;
    shapes.push_back(std::move(triangle));

    float clear_color[4] = { 0.2f, 0.3f, 0.3f, 1.0f };
    
    MAIN_LOOP(graphics){
        graphics.PollEvents();
        graphics.ClearColor(clear_color[0], clear_color[1], clear_color[2], clear_color[3]);

        graphics.camera.AspectRatio = graphics.GetAspectRatio();

        if (FE::Input::IsKeyPressed(FE::Key::F4) && FE::Input::IsKeyPressed(FE::Key::LeftAlt)) {
            graphics.CloseWindow();
        }

        // graphics.gui_comp.BeginGUI();
            // DebugMenu::Run(clear_color);
            // DebugMenu::Run_Transform("Transform Object_0", myRect);
        // graphics.gui_comp.EndGUI();

        myShader.Use();
        myShader.SetMat4("u_view", graphics.camera.GetViewMatrix());
        myShader.SetMat4("u_projection", graphics.camera.GetProjectionMatrix());

        // 描画
        for (const auto& shape : shapes) {
            shape->Draw(myShader);
        }

        graphics.SwapBuffers();
    }

    return 0;
}