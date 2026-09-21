#ifndef RENDERER__
#define RENDERER__

#include "elements/baseObject.hpp"
#include <GLFW/glfw3.h>
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <vector>
#include <memory>

class Renderer{
    unsigned int quadVbo = 0;
    unsigned int dataVbo = 0;
    unsigned int Vao = 0;

    unsigned int vertexShader;
    unsigned int fragmentShader;
    unsigned int shaderProgram;
    unsigned int projectionLocation;
    
    float quadVertices[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,

        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f
    };

    glm::mat4 projection = glm::ortho(
        0.0f,
        1920.0f,
        1080.0f,
        0.0f
    );

    bool initComplete = false;

public:
    Renderer();

    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    
    void render(std::vector<std::unique_ptr<baseObject>>& elements);
    void resize(int width, int height);
    void init();
};

#endif