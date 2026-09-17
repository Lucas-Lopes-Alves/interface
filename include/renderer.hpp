#ifndef __RENDERER__
#define __RENDERER__

#include "elements/baseObject.hpp"
#include <vector>

class Renderer{
    unsigned int quadVbo;
    std::vector<baseObject> instances;

public:
    Renderer();
    
    void submit(baseObject&);

    void load();
};

#endif