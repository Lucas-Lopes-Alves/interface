#ifndef __RENDERER__
#define __RENDERER__

#include "elements/baseObject.hpp"
#include <vector>
class Renderer{
    unsigned int quadVbo;
    unsigned int quadVao;
    unsigned int dataVbo;
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
    
    void render(std::vector<baseObject>& elements);

    void init();
};

#endif