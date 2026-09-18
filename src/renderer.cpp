#include "renderer.hpp"
#include "elements/baseObject.hpp"
#include "elements/button.hpp"
#include "glFunc.hpp"
#include "glad/gl.h"
#include <iostream>
#include <vector>

Renderer::Renderer(){}

Renderer::~Renderer(){
    glDeleteBuffers(1,&quadVbo);
    quadVbo = 0;
    glDeleteBuffers(1,&dataVbo);
    dataVbo = 0;
    glDeleteVertexArrays(1, &quadVao);
    quadVao = 0;
}

void Renderer::render(std::vector<baseObject>& elements){
    if (quadVbo == 0 || quadVao== 0 || dataVbo == 0){
        std::cerr << "Vertices buffer not initialized";
        return;
    }
    
    OpenGL::uploadVBO(quadVbo, quadVertices, sizeof(quadVertices));
}

void Renderer::init(){
    quadVbo = OpenGL::createVBO();
    dataVbo = OpenGL::createVBO();
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
    quadVao = OpenGL::createVAO(0,2,2*sizeof(float),0);
}