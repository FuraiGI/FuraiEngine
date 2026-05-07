#ifndef BASE_SHAPE_HPP
#define BASE_SHAPE_HPP

#include <graphic/Shader.hpp>

namespace FuraiEngine {
    namespace Shape {
        // すべての図形の共通プロパティを持つ親クラス
        class Shape {
        public:
            float x = 0.0f, y = 0.0f;
            float angle = 0.0f;
            float scaleX = 1.0f, scaleY = 1.0f;

            virtual ~Shape() {}

            // 子クラスで必ず実装する描画関数
            virtual void Draw(const Shader& shader) const = 0;
        };
    }
}

#endif // BASE_SHAPE_HPP