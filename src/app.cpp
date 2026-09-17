#include "app.hpp"
#include "wrapper.hpp"
#include <GLFW/glfw3.h>
#include <string>

App::App(int width, int height, std::string title)
: global(), loader(), mainWindow(width,height,title){
    global.loadOpenGL();
}

App::~App(){
    mainWindow.~Window();
    global.~WindowConfig();
}

void App::run(){
    while(!mainWindow.windowShouldClose()){
        mainWindow.swapBuffers();
        this->setElements();
        global.pollEvents();
    }
}

void App::ViewportResizeCallback(GLFWframebuffersizefun func){
    mainWindow.setFramebufferSizeCallback(func);
}

void App::addButton(baseObject object){
    loader.submit(object);
}

void App::render(){
    
}