#include "elements/button.hpp"

void Button::clicked(){
    if (clickCallback){
        clickCallback();
    }
}

void Button::setClickAction(void (*func)()){
    clickCallback = func;
}