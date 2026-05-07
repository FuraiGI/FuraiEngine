#include <graphic/shape/Polygon.hpp>
#include <cmath>

namespace FuraiEngine {
    namespace Shape {

        // 頂点データを計算して配列を作るヘルパー関数
        std::vector<float> GeneratePolygonVertices(int segments, float radiusX, float radiusY) {
            std::vector<float> vertices;
            const float PI = 3.14159265359f;
            
            for (int i = 0; i < segments; ++i) {
                float theta1 = (2.0f * PI * i) / segments;
                float theta2 = (2.0f * PI * (i + 1)) / segments;

                float offset = PI / 2.0f;

                vertices.push_back(0.0f); vertices.push_back(0.0f); vertices.push_back(0.0f);
                
                vertices.push_back(std::cos(theta1 - offset) * radiusX);
                vertices.push_back(std::sin(theta1 - offset) * radiusY);
                vertices.push_back(0.0f);
                
                vertices.push_back(std::cos(theta2 - offset) * radiusX);
                vertices.push_back(std::sin(theta2 - offset) * radiusY);
                vertices.push_back(0.0f);
            }
            return vertices;
        }

        // 初期化子リストでMeshを生成
        Polygon::Polygon(int segments, float radiusX, float radiusY)
            : _mesh(GeneratePolygonVertices(segments, radiusX, radiusY)) 
        {
        }

        void Polygon::Draw(const Shader& shader) const {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, glm::vec3(x, y, 0.0f));
            model = glm::rotate(model, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
            model = glm::scale(model, glm::vec3(scaleX, scaleY, 1.0f));
            
            shader.SetMat4("u_model", model);
            _mesh.Draw();
        }

    }
}