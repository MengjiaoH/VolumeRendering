#version 410 core

layout(location = 0) out vec4 fragColor;

//in vec3 texCoords;

void main(){
    //vec3 color = texCoords;
    vec3 color = vec3(1.0, 0.0, 0.0);
    fragColor = vec4(color, 1.0);
}
