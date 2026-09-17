#include "renderer.hpp"
#include "elements/button.hpp"
#include "glFunc.hpp"

Renderer::Renderer(){}

void Renderer::submit(baseObject& object){
    instances.push_back(object);
}

void Renderer::load(){
    quadVbo = OpenGL::createVBO();
    // OpenGL::uploadVBO(quadVbo, Button::vertices, std::size_t size);
}