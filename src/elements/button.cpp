#include "elements/button.hpp"

void Button::clicked(){
    for (auto& funcs : callbacks){
        funcs();
    }
}

void Button::connect(void (*func)()){
    callbacks.push_back(func);
}