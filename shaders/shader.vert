#version 330 core

uniform mat4 projection;

layout(location = 0) in vec2 aPos;
layout(location = 1) in vec2 aSize;
layout(location = 2) in vec2 aPosition;
layout(location = 3) in vec4 aColor;
out vec4 vertexColor;

void main(){
    
  vec2 aFinal = aPos * aSize + aPosition;
  
  gl_Position = projection * vec4(aFinal,0.0,1.0); 
  vertexColor = aColor;
}