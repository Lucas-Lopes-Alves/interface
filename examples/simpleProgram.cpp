#include "app.hpp"
#include "elements/button.hpp"
#include <iostream>

void foo(){
    std::cout << "hello\n";
}

int main(){
    App main(200,200,"Hello World");
    
    Button button;
    button
        .setColor(213.f,190.f,212.f,1.f)
        .setPosition(10.0f,30.0f)
        .setSize(20.0f,20.0f);    

    button.connect(foo);
    
    main.addButton(button);
    main.run();
}