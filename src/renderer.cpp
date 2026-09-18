#include "renderer.hpp"
#include "elements/baseObject.hpp"
#include "elements/button.hpp"
#include "glFunc.hpp"
#include "glad/gl.h"
#include <vector>

Renderer::Renderer(){}

void Renderer::render(std::vector<baseObject>& elements){
    OpenGL::uploadVBO(quadVbo, quadVertices, sizeof(quadVertices));
}

void Renderer::init(){
    quadVbo = OpenGL::createVBO();
    dataVbo = OpenGL::createVBO();
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
    quadVao = OpenGL::createVAO(0,2,2*sizeof(float));
}