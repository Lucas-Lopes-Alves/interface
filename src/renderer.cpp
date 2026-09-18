#include "renderer.hpp"
#include "elements/button.hpp"
#include "glFunc.hpp"

Renderer::Renderer(){
    quadVbo = OpenGL::createVBO();
    quadVao = OpenGL::createVAO(0,2,2*sizeof(float));
}

void Renderer::submit(baseObject& object){
    instances.push_back(&object);
}

void Renderer::load(){
    OpenGL::uploadVBO(quadVbo, quadVertices, sizeof(quadVertices));
}