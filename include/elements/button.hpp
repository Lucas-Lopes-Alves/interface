#ifndef BUTTON__
#define BUTTON__

#include "elements/baseObject.hpp"

class Renderer;

class Button : public baseObject{
    void clicked() override;
    void (*clickCallback)() = nullptr;
public:
    Button() = default;
    void setClickAction(void (*func)());
};

#endif