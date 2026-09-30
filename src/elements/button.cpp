#include "elements/button.hpp"

Button::Button(){
    size = {100.f,50.f};
    position = {0.0f,0.0f};
    color = {47.f,79.f,79.f,1.f};
}

void Button::clicked(){
    for (auto& funcs : callbacks){
        funcs();
    }
}

void Button::connect(void (*func)()){
    callbacks.push_back(func);
}