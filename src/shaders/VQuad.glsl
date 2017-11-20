#version 410 core

in vec3 pos;

out vec2 tex;

void main(){
    gl_Position = vec4(pos, 1.0);
    tex = pos.xy * 0.5 + 0.5;
}