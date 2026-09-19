#ifndef RENDERER__
#define RENDERER__

#include "elements/baseObject.hpp"
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

    bool canExecute = false;
    bool initComplete = false;
public:
    Renderer();

    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    
    void render(std::vector<std::unique_ptr<baseObject>>& elements);

    void init();
};

#endif