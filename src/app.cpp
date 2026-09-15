#include "app.hpp"
#include "wrapper.hpp"
#include <GLFW/glfw3.h>
#include <string>

App::App(int width, int height, std::string title)
: global(), window(width,height,title){
    global.loadOpenGL();
}

App::~App(){
    window.~Window();
    global.~WindowConfig();
}

void App::run(){
    while(!window.windowShouldClose()){
        window.swapBuffers();
        
        global.pollEvents();
    }
}

void App::ViewportResizeCallback(ViewportSizeCallback func){
    window.setFramebufferSizeCallback(func);
}