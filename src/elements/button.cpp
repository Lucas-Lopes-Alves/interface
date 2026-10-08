#include "elements/button.hpp"
#include "vectors.hpp"

Button::Button(){
    size = {100.f,50.f};
    position = {0.0f,0.0f};
    style.color = {47.f,79.f,79.f,1.f};
}

void Button::clicked(){
    for (auto& funcs : callbacks){
        funcs();
    }
}

void Button::connect(void (*func)()){
    callbacks.push_back(func);
}

Button& Button::setColor(float x,float y,float z,float w){
    style.color = {x,y,z,w};
    return *this;
}

Vec::Vector4 Button::getColor(){
    return style.color;
}