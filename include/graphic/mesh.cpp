#include <graphic/Mesh.hpp>

namespace FuraiEngine {

    Mesh::Mesh(const std::vector<float>& vertices) {
        // 頂点数を計算 (1頂点につきX,Y,Zの3要素あると仮定)
        vertexCount = vertices.size() / 3;

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);

        glBindVertexArray(VAO);
        
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        // std::vector の内部データのポインタ (.data()) と、全体のバイト数 (.size() * sizeof(float)) を渡す
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

        // Location 0 に 3要素ずつ(X,Y,Z) 読み込む設定
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        // バインド解除
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    Mesh::~Mesh() {
        // クラスが破棄されるときに、自動でGPUのメモリもお掃除する
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
    }

    void Mesh::Draw() const {
        // この図形（VAO）をバインドして描画する
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertexCount);
        glBindVertexArray(0); // お行儀よく解除
    }

}