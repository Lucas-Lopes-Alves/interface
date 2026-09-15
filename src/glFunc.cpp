#include <cstddef>
#include "glad/gl.h"
#include "glFunc.hpp"

GLuint OpenGL::createVBO(const void* vertices, std::size_t size){
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glBufferData(
        GL_ARRAY_BUFFER,
        size,
        vertices,
        GL_STATIC_DRAW
    );

    return VBO;
}

GLuint OpenGL::createVAO(int location, int quantity, int size, std::size_t start){
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glVertexAttribPointer(
        location,                  // location
        quantity,                  // quantidade de valores
        GL_FLOAT,           // tipo
        GL_FALSE,
        size,  // tamanho de cada vértice
        (void*)start            // offset
    );
    glEnableVertexAttribArray(0);

    return VAO;
}

GLuint OpenGL::createVertexShader(const char*& source, std::size_t count){
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,count, &source, nullptr);
    glCompileShader(vertexShader);
    return vertexShader;
}

GLuint OpenGL::createFragmentShader(const char*& source, std::size_t count){
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, count, &source, nullptr);
    glCompileShader(fragmentShader);
    return fragmentShader;
}
