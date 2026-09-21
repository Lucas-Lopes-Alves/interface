#include "glad/gl.h"
#include "glFunc.hpp"
#include "renderer.hpp"
#include "elements/baseObject.hpp"
#include "elements/button.hpp"
#include <GL/glext.h>
#include <glm/ext/matrix_float4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>
#include <vector>
#include <memory>
#include "exceptions/shaderCompileError.hpp"

void checkCompileError(GLuint shaderID){
    GLint success;
    
    //Consulta o status de compilação (GL_COMPILE_STATUS)
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
    
    //Se o resultado for GL_FALSE, a compilação falhou
    if (success == GL_FALSE) {
        GLint logLength;
        // Descobre o tamanho da mensagem de erro
        glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &logLength);
        
        // Cria um buffer para armazenar o texto do erro
        std::vector<GLchar> errorLog(logLength);
        glGetShaderInfoLog(shaderID, logLength, &logLength, &errorLog[0]);
        
        // Lança a exceção
        throw shader_compile_error("Erro na compilação do shader:", &errorLog[0]);
    }

}

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

const char *const vertexShaderSource = R"(
    #version 330 core
    
    uniform mat4 projection;
    
    layout(location = 0) in vec2 aPos;
    layout(location = 1) in vec2 aSize;
    layout(location = 2) in vec2 aPosition;
    
    void main(){
      vec2 aFinal = aPos * aSize + aPosition;
      
      gl_Position = projection * vec4(aFinal,0.0,1.0); 
      
    }
)";

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

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    checkCompileError(vertexShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    
    projectionLocation = glGetUniformLocation(shaderProgram, "projection");
    glUseProgram(shaderProgram);
    glUniformMatrix4fv(
        projectionLocation,
        1,
        GL_FALSE,
        glm::value_ptr(projection)
    );
    initComplete = true;
}

void Renderer::resize(int width, int height){
    projection = glm::ortho(
        0.0f,
        static_cast<float>(width),
        static_cast<float>(height),
        0.0f
    );
    glViewport(0,0,width,height);

    if (shaderProgram){
        glUseProgram(shaderProgram);
        glUniformMatrix4fv(
            projectionLocation,
            1,
            GL_FALSE,
            glm::value_ptr(projection)
        );
    }
}