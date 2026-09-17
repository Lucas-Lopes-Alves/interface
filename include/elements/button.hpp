#ifndef __BUTTON__
#define __BUTTON__

#include "elements/baseObject.hpp"

class Button : public baseObject{
    float vertices[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,

        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f
    };

public:

    Button() = default;

    void draw(Window& target, unsigned int VBO) override;
};

#endif