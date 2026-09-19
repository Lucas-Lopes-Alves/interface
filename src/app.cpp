#include "glad/gl.h"
#include "app.hpp"
#include "wrapper.hpp"
#include <GLFW/glfw3.h>
#include <memory>
#include <stdexcept>
#include <string>

App::App(int width, int height, std::string title)
: global(), mainWindow(width,height,title), loader(){
    global.setContext(mainWindow);
    
    if(!gladLoadGL(glfwGetProcAddress)){
        throw std::runtime_error("Error at loading OpenGL");
    }

    loader.init();
}

void App::run(){
    this->setElements();
    while(!mainWindow.windowShouldClose()){
        global.pollEvents();
        render();
        mainWindow.swapBuffers();
    }
}

void App::ViewportResizeCallback(GLFWframebuffersizefun func){
    mainWindow.setFramebufferSizeCallback(func);
}

template<typename T>
void App::addButton(T& object){
    childrenElements.push_back(std::make_unique<T>(std::move(object)));
}

void App::render(){
    loader.render(childrenElements);
}