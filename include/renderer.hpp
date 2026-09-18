#ifndef __RENDERER__
#define __RENDERER__

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
    
    void render(std::vector<baseObject>& elements);

    void init();
};

#endif