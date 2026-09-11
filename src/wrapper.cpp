#include "glad/gl.h"
#include <GLFW/glfw3.h>
#include <GL/gl.h>
#include <stdexcept>
#include <string>
#include "wrapper.hpp"

// Window implementations

// Constructor
Window::Window(int width,int height, const std::string& title): width(width), height(height), title(title){

    this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);

    if (!this->window){
        throw std::runtime_error("Error creating the window");
    }
    
    glfwMakeContextCurrent(this->window);
}

// Destructor
Window::~Window(){
    glfwDestroyWindow(this->window);
}

void Window::setFramebufferSizeCallback(GLFWframebuffersizefun func){
    glfwSetFramebufferSizeCallback(this->window, func);
}

int Window::windowShouldClose(){
    return glfwWindowShouldClose(this->window);
}

void Window::swapBuffers() {
    glfwSwapBuffers(this->window);
}

// GlobalWindow implementations
GlobalWindow::GlobalWindow(){
    if (!glfwInit()){
        throw std::runtime_error("Error initializing the global configuration");
    }
}

GlobalWindow::~GlobalWindow(){
    glfwTerminate();
}

void GlobalWindow::pollEvents(){
    glfwPollEvents();
}

void GlobalWindow::loadOpenGL(){
    gladLoadGL(glfwGetProcAddress);
}