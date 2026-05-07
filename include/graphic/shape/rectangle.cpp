#include <graphic/shape/Rectangle.hpp>

namespace FuraiEngine {
    namespace Shape {

        Rectangle::Rectangle(float width, float height)
            : _mesh({
                -width / 2.0f, -height / 2.0f, 0.0f,
                 width / 2.0f, -height / 2.0f, 0.0f,
                 width / 2.0f,  height / 2.0f, 0.0f,

                -width / 2.0f, -height / 2.0f, 0.0f,
                 width / 2.0f,  height / 2.0f, 0.0f,
                -width / 2.0f,  height / 2.0f, 0.0f
            }) 
        {
            // Meshの生成は初期化子リストで終わっているので,中身は空でOK
        }

        void FuraiEngine::Shape::Rectangle::Draw(const Shader& shader) const {
            // 1. 単位行列（何もしない行列）を作る
            glm::mat4 model = glm::mat4(1.0f);

            // 2. 移動 (Translate)
            model = glm::translate(model, glm::vec3(x, y, 0.0f));
            
            // 3. 回転 (Rotate) - Z軸を中心に回転させる
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
            
            // 4. 拡大縮小 (Scale)
            model = glm::scale(model, glm::vec3(scaleX, scaleY, 1.0f));

            // 5. 完成した行列をシェーダーに送る
            shader.SetMat4("u_model", model);

            // 6. 描画
            _mesh.Draw();
        }

    }
}