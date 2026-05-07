#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <graphic/Mesh.hpp>
#include <graphic/Shader.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <graphic/shape/BaseShape.hpp>

namespace FuraiEngine {
    namespace Shape {
        class Polygon : public Shape{
        private:
            Mesh _mesh;

        public:
            float x      = 0.0f, y      = 0.0f;
            float angle  = 0.0f;
            float scaleX = 1.0f, scaleY = 1.0f;

            // segments: 角の数（3なら三角形、36なら円）
            // radiusX, radiusY: 横と縦の半径
            Polygon(int segments, float radiusX, float radiusY);

            void Draw(const Shader& shader) const override;
        };
    }
}

#endif // POLYGON_HPP