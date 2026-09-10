#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdexcept>
#include <string>
#include "wrapper.hpp"


// Constructor
Window::Window(int width,int height, const std::string& title): width(width), height(height), title(title){

    this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), nullptr, nullptr);

    if (!this->window){
        throw std::runtime_error("Error creating the window");
    }
}

// Destructor
Window::~Window(){
    glfwDestroyWindow(this->window);
}

void Window::setFramebufferSizeCallback(GLFWframebuffersizefun func){
    glfwSetFramebufferSizeCallback(this->window, func);
}

void Window::MakeContextCurrent(){
    glfwMakeContextCurrent(this->window);
}

int Window::WindowShouldClose(){
    return glfwWindowShouldClose(this->window);
}

void Window::SwapBuffer() {
    glfwSwapBuffers(this->window);
}

void Window::PollEvents(){
    glfwPollEvents();
}



GlobalWindow::GlobalWindow(){
    if (!glfwInit()){
        throw std::runtime_error("Error initializing the global configuration");
    }
}

GlobalWindow::~GlobalWindow(){
    glfwTerminate();
}
