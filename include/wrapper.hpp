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

    void MakeContextCurrent();

    int WindowShouldClose();

    void SwapBuffers();

};

class GlobalWindow{

public:
    GlobalWindow();

    ~GlobalWindow();
    
    void PollEvents();
};