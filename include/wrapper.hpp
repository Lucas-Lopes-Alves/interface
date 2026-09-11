#pragma once

#include <GLFW/glfw3.h>
#include <string>

class Window{  
    int width;
    int height;
    std::string title;
    GLFWwindow* window;  
    
public:
    // Constructor
    Window(int width,int height, const std::string& title);

    // Destructor
    ~Window();
    
    void setFramebufferSizeCallback(GLFWframebuffersizefun func);

    int windowShouldClose();

    void swapBuffers();

};

class GlobalWindow{

public:
    GlobalWindow();

    ~GlobalWindow();
    
    void pollEvents();

    void loadOpenGL();
};