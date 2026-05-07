#ifndef SHADER_HPP
#define SHADER_HPP

#include <glad/glad.h>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp> // value_ptr用

namespace FuraiEngine {
    class Shader {
    public:
        // シェーダープログラムのID
        unsigned int ID;

        void SetFloat(const std::string &name, float value) const;
        void SetMat4(const std::string &name, const glm::mat4 &mat) const;
        
        // ファイルパスを受け取り,読み込みとコンパイルを行う
        Shader(const char* vertexPath, const char* fragmentPath);
        ~Shader();

        // シェーダープログラムの有効化
        void Use();
    };
}

#endif // SHADER_HPP