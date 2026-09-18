#include "renderer.hpp"
#include "elements/baseObject.hpp"
#include "elements/button.hpp"
#include "glFunc.hpp"
#include <vector>

Renderer::Renderer(){
    quadVbo = OpenGL::createVBO();
    dataVbo = OpenGL::createVBO();
    quadVao = OpenGL::createVAO(0,2,2*sizeof(float));
}

void Renderer::render(std::vector<baseObject>& elements){
    OpenGL::uploadVBO(quadVbo, quadVertices, sizeof(quadVertices));
    
}