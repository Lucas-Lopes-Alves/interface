#ifndef RENDERER__
#define RENDERER__

#include "elements/baseObject.hpp"
#include <vector>
class Renderer{
    unsigned int quadVbo = 0;
    unsigned int quadVao = 0;
    unsigned int dataVbo = 0;
    float quadVertices[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,

        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f
    };
public:
    Renderer();

    ~Renderer();

    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    
    void render(std::vector<baseObject>& elements);

    void init();
};

#endif