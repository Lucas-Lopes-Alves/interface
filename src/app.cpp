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
    
    App* app = static_cast<App*>(glfwGetWindowUserPointer(window));
    if (!app){ return; }

    
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS){
        for (auto& data : app->childrenElements){
            auto position = data->getPosition();
            auto size = data->getSize();
            if (mouseX >= position.x && mouseX <= position.x + size.x
                && mouseY >= position.y && mouseY <= position.y + size.y)
            {
                std::cout
                    << "Mouse: "
                    << mouseX << ", " << mouseY
                    << "\n";
                
                std::cout
                    << "Element position: "
                    << position.x << ", " << position.y
                    << "\n";
                
                std::cout
                    << "Element size: "
                    << size.x << ", " << size.y
                    << "\n";
                data->clicked();
                break;
            }
        }
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