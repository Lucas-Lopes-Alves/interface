#pragma once

#include <GLFW/glfw3.h>
#include <string>

class Window{
    int width;
    int height;
    std::string title;
public:
    GLFWwindow* window;

    // Constructor
    Window(int width,int height, const std::string& title);

    // Destructor
    ~Window();

    // Prevent initialization from another Window
    // e.g.
    //
    // Window b(200,200,"title");
    // Window a = b;
    Window(const Window&) = delete;

    // Prevent assignment from another Window
    // e.g.
    //
    // Window a(200,200,"title");
    // Window b;
    // b = a;
    Window& operator =(const Window&) = delete;

    // Allows move operations in initialization
    // e.g.
    //
    // Window b(200,200,"title");
    // Window a = std::move(b);
    Window(Window&& other) noexcept;

    // Allow move assignments from another Window
    // e.g.
    //
    // Window a(200,200,"title");
    // Window b;
    // b = a;
    Window& operator=(Window&& other) noexcept;

    void setFramebufferSizeCallback(GLFWframebuffersizefun func);

    bool windowShouldClose();

    void swapBuffers();

};

class WindowConfig{

public:
    WindowConfig();

    ~WindowConfig();

    void pollEvents();

    void loadOpenGL();

    void setContext(Window&);
};