#include "app.hpp"
#include "elements/button.hpp"

// Creates the class tha derives from app class
class meuApp : public App{
    using App::App;
    void setElements() override{
        Button button;
        button.setColor(256.f,0.f,0.f,1.f)
            .setPosition(100.f,100.0f)
            .setSize(100.0f,100.0f);
        
        Button button2;
        button2
            .setColor(0.0f, 0.0f, 256.0f, 1.0f)
            .setPosition(100.0f, 100.0f)
            .setSize(50.0f, 20.0f);
        
        this->addButton(button);
        this->addButton(button2);
    }
};

int main(){
    meuApp main(200,200,"Hello World");
    main.run();
}