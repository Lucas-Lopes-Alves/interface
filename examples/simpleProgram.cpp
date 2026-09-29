#include "app.hpp"
#include "elements/button.hpp"
#include <iostream>

void foo(){
    std::cout << "hello\n";
}

int main(){
    App main(200,200,"Hello World");
    
    Button firstButton;
    firstButton
        .setColor(213.f,190.f,212.f,1.f)
        .setPosition(10.0f,30.0f)
        .setSize(20.0f,20.0f);
    
    Button secondButton;
    secondButton
        .setColor(215.0f, 88.0f, 12.0f, 0.5f)
        .setPosition(100.0f,100.0f)
        .setSize(20.0f, 20.0f);

    firstButton.connect(foo);
    secondButton.connect([](){
        std::cout << "Hi ";
    });
    secondButton.connect([](){
        std::cout << "my friend\n";
    });
    
    main.addButton(firstButton);
    main.addButton(secondButton);
    main.run();
}