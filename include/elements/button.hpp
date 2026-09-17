#ifndef __BUTTON__
#define __BUTTON__

#include "elements/baseObject.hpp"

class Renderer;

class Button : public baseObject{
public:
    Button() = default;

protected:
    float vertices[12] = {
        -0.5f, 0.5f,
        0.5f, 0.5f,
        0.5f, -0.5f,

        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f
    };
    void draw(Renderer&) override;
};

#endif