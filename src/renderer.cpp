#include "glad/gl.h"
#include "glFunc.hpp"
#include "renderer.hpp"
#include "elements/baseObject.hpp"
#include "elements/button.hpp"
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>
#include <vector>
#include <memory>

Renderer::Renderer(){}

Renderer::~Renderer(){
    glDeleteBuffers(1,&quadVbo);
    quadVbo = 0;
    glDeleteBuffers(1,&dataVbo);
    dataVbo = 0;
    glDeleteVertexArrays(1, &Vao);
    Vao = 0;
}

void Renderer::render(std::vector<std::unique_ptr<baseObject>>& elements){
    if (!initComplete){
        throw std::runtime_error("Renderer initialization incomplete");
        return;
    }

    if (quadVbo == 0 || Vao== 0 || dataVbo == 0){
        throw std::runtime_error("Vertices buffer not initialized");
        return;
    }
}

void Renderer::init(){
    quadVbo = OpenGL::createVBO();
    dataVbo = OpenGL::createVBO();
    Vao = OpenGL::createVAO();
    
    glBindBuffer(GL_ARRAY_BUFFER, quadVbo);
    glBindVertexArray(Vao);
    
    glVertexAttribPointer(
        0,
        2,
        GL_FLOAT,
        GL_FALSE,
        2 * sizeof(float),
        (void*)0
    );
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, dataVbo);

    glVertexAttribPointer(
        1,
        2,
        GL_FLOAT,
        GL_FALSE,
        8 * sizeof(float),
        (void*)0
    );
    glEnableVertexAttribArray(1);

    glVertexAttribPointer(
        2,
        2,
        GL_FLOAT,
        GL_FALSE,
        8 * sizeof(float),
        (void*)(2 * sizeof(float))
    );
    glEnableVertexAttribArray(2);

    glVertexAttribPointer(
        3,
        4,
        GL_FLOAT,
        GL_FALSE,
        8 * sizeof(float),
        (void*)(4 * sizeof(float))
    );
    glEnableVertexAttribArray(3);

    glVertexAttribDivisor(1, 1);
    glVertexAttribDivisor(2, 1);
    glVertexAttribDivisor(3, 1);
    
    OpenGL::uploadVBO(quadVbo, quadVertices, sizeof(quadVertices));
    initComplete = true;
}

void Renderer::resize(float width, float height){
    projection = glm::ortho(
        0.0f,
        width,
        height,
        0.0f
    );
    glViewport(0,0,width,height);
}