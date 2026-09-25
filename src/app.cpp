#include "glad/gl.h"
#include "app.hpp"
#include "wrapper.hpp"
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>
#include <string>

void App::sizeCallback(GLFWwindow* window, int width, int height){
    App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
    app->onResize(width, height);
}

void mouseCallback(GLFWwindow* window, int button, int action, int mods){
    double mouseX;
    double mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
    
    int width;
    int height;
    glfwGetWindowSize(window, &width, &height);

    App* app = static_cast<App*>(glfwGetWindowUserPointer(window));

    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        for (auto& data : app->childrenElements){
            float positionX;
            float positionY;
            positionX = data->getPosition().x;
            positionY = data->getPosition().x;
            // if (mouseX)
        }
    }
    

    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS){
        std::cout << "oi\n";
    }
}

App::App(int width, int height, std::string title)
: global(), mainWindow(width,height,title), loader(), windowX(width), windowY(height){
    global.setContext(mainWindow);
    
    if(!gladLoadGL(glfwGetProcAddress)){
        throw std::runtime_error("Error at loading OpenGL");
    }

    mainWindow.setUserPointer(this);
    
    mainWindow.setFramebufferSizeCallback(App::sizeCallback);
    mainWindow.setMouseButtonCallback(mouseCallback);
    loader.init();
    loader.resize(width, height);
}

void App::run(){
    
    this->setElements();
    while(!mainWindow.windowShouldClose()){
        
        global.pollEvents();
        loader.load(childrenElements);
        mainWindow.getCursorPos(mouseX, mouseY);
        
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