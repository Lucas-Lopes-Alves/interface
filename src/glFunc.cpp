#include <cstddef>
#include "glad/gl.h"

GLuint createVBO(const void* vertices, std::size_t size){
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

GLuint createVAO(){
    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    glVertexAttribPointer(
        0,                  // location
        2,                  // quantidade de valores
        GL_FLOAT,           // tipo
        GL_FALSE,
        2 * sizeof(float),  // tamanho de cada vértice
        (void*)0            // offset
    );
    glEnableVertexAttribArray(0);

    return VAO;
}

GLuint createVertexShader(const char*& source, std::size_t count){
    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader,count, &source, nullptr);
    glCompileShader(vertexShader);
    return vertexShader;
}

GLuint createFragmentShader(const char*& source, std::size_t count){
    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, count, &source, nullptr);
    glCompileShader(fragmentShader);
    return fragmentShader;
}
