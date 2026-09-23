#version 330 core

in vec4 vertexColor;

out vec4 fragColor;

void main(){
    fragColor = vec4(vertexColor.x/256.0,vertexColor.y/256.0,vertexColor.z/256.0,vertexColor.w);
}