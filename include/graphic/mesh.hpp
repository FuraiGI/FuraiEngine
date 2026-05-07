#ifndef MESH_HPP
#define MESH_HPP

#include <glad/glad.h>
#include <vector>

namespace FuraiEngine {
    class Mesh {
    private:
        unsigned int VAO, VBO;
        int vertexCount; // 描画する頂点の数

    public:
        // コンストラクタ：floatの配列（std::vector）を受け取る
        Mesh(const std::vector<float>& vertices);
        
        // デストラクタ：GPUメモリを解放する
        ~Mesh();

        // コピーを禁止する（同じVAOが2回破棄されるのを防ぐため）
        Mesh(const Mesh&) = delete;
        Mesh& operator=(const Mesh&) = delete;

        // 描画メソッド
        void Draw() const;
    };
}

#endif // MESH_HPP