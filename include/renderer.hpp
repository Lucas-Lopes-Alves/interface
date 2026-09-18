#ifndef __RENDERER__
#define __RENDERER__

#include "elements/baseObject.hpp"
#include <vector>

class Renderer{
    unsigned int quadVbo;
    unsigned int quadVao;
    std::vector<baseObject*> instances;
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
    
    void submit(baseObject&);

    void load();
};

#endif