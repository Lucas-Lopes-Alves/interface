#include "app.hpp"
#include "elements/button.hpp"
#include <iostream>

void foo(){
    std::cout << "ola\n";
}

// Creates the class that derives from app class
class myApp : public App{
    using App::App;
    void setElements() override{
        Button button;
        button.setColor(256.f,0.f,0.f,1.f)
            .setPosition(10.f,10.0f)
            .setSize(100.0f,100.0f);
        
        Button button2;
        button2
            .setColor(0.0f, 0.0f, 256.0f, 1.0f)
            .setPosition(10.0f, 10.0f)
            .setSize(50.0f, 20.0f);

        button.setClickAction(foo);
        
        this->addButton(button);
        this->addButton(button2);
    }
};

int main(){
    myApp main(200,200,"Hello World");
    main.run();
}