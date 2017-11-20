#version 410 core

layout(location = 0) out vec4 fragColor;

uniform sampler2D texture2D;

in vec2 tex;


void main(){
    vec3 color = texture(texture2D, tex).rgb;
    fragColor = vec4(color, 1.0);
}