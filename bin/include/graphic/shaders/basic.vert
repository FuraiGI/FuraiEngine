#version 330 core
layout (location = 0) in vec3 aPos;

// 魔法の3つの行列 (MVP)
uniform mat4 u_model;      // 図形自身の位置・回転・スケール
uniform mat4 u_view;       // カメラの位置・ズーム
uniform mat4 u_projection; // 画面の比率（レンズ）

void main()
{
    // 計算順序は必ず P * V * M * 頂点 の順番！
    gl_Position = u_projection * u_view * u_model * vec4(aPos, 1.0);
}