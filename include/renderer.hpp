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
    float quadVertices[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,

        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f
    };

    bool initComplete = false;

    glm::mat4 projection = glm::ortho(
        0.0f,
        1920.0f,
        1080.0f,
        0.0f
    );

    unsigned int projectionLocation;
public:
    Renderer();

    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    
    void render(std::vector<std::unique_ptr<baseObject>>& elements);
    void resize(float width, float height);
    void init();
};

#endif