#include "glad/gl.h"
#include "app.hpp"
#include "wrapper.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>

void App::callback (GLFWwindow* window, int width, int height){
    App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
    app->onResize(width, height);
}

App::App(int width, int height, std::string title)
: global(), mainWindow(width,height,title), loader(){
    global.setContext(mainWindow);
    
    if(!gladLoadGL(glfwGetProcAddress)){
        throw std::runtime_error("Error at loading OpenGL");
    }

    mainWindow.setUserPointer(this);
    
    mainWindow.setFramebufferSizeCallback(App::callback);
    loader.init();
    loader.resize(width, height);
}

void App::run(){
    this->setElements();
    while(!mainWindow.windowShouldClose()){
        global.pollEvents();
        loader.load(childrenElements);
        loader.resize(200, 200);
        render();
        mainWindow.swapBuffers();
    }
}

void App::render(){
    loader.render(childrenElements);
}

void App::onResize(int width, int height)
{
    loader.resize(width, height);
}