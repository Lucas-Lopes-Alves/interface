#include "elements/button.hpp"
#include "vectors.hpp"

Button::Button(){
    size = {100.f,50.f};
    position = {0.0f,0.0f};
    style.color = {47.f,79.f,79.f,1.f};
}

void Button::clicked(){
    auto callbacksCopy = callbacks;
    for (auto& funcs : callbacksCopy){
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

Button& Button::setBorderSize(float size){
    style.borderSize = size;
    return *this;
}

Button& Button::setBorderColor(float x,float y,float z,float a){
    style.borderColor.x = x;
    style.borderColor.y = y;
    style.borderColor.z = z;
    style.borderColor.a = a;
    return *this;
}

Button& Button::setVisibility(bool visibility){
    style.visible = visibility;
    return *this;
}

bool Button::getVisibility(){
    return style.visible;
}

Style Button::getStyle() const{
    return style;
}