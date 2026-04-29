#version 330 core
layout (location = 0) in vec3 aPos;

uniform float u_aspectRatio; 
uniform mat4 u_model; // ★追加：モデル行列 (4x4)

void main()
{
    // 1. 頂点座標に行列を「掛け算」して、移動・回転・拡大を適用する
    vec4 worldPos = u_model * vec4(aPos, 1.0);
    
    // 2. 最後にアスペクト比で補正
    gl_Position = vec4(worldPos.x / u_aspectRatio, worldPos.y, worldPos.z, 1.0);
}