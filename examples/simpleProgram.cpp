#include "app.hpp"
#include "elements/button.hpp"
#include <iostream>

void foo(){
    std::cout << "hello\n";
}

// Creates the class that derives from app class
class myApp : public App{
    using App::App;
    void setElements() override{
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
    
        firstButton.setClickAction(foo);
        secondButton.setClickAction([](){
            std::cout << "Hi\n";
        });
        
        this->addButton(firstButton);
        this->addButton(secondButton);
    }
};

int main(){
    myApp main(200,200,"Hello World");
    main.run();
}