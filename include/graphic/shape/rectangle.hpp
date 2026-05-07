#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <graphic/Mesh.hpp>
#include <graphic/shader.hpp>
#include <graphic/shape/BaseShape.hpp>

namespace FuraiEngine{
    namespace Shape{
        class Rectangle : public Shape{
            private:
                Mesh _mesh;
            public:
                float x = 0.0f, y = 0.0f;               // 位置      (Translation)
                float angle = 0.0f;                     // 回転      (Rotation) ※度数法(Degree)
                float scaleX = 1.0f, scaleY = 1.0f;     // 拡大縮小  (Scale)
                
                Rectangle(float width, float height);
                
                void Draw(const Shader& shader) const override;
            };

    }
}

#endif // RECTANGLE_HPP