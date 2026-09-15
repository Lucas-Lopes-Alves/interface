#ifndef APP_CLASS
#define APP_CLASS

// #include "glad/gl.h"
// #include "glFunc.hpp"
#include <GLFW/glfw3.h>
#include "wrapper.hpp"
#include <string>

typedef GLFWframebuffersizefun ViewportSizeCallback;

class App{
private:
    WindowConfig global;
    Window window;

    void ViewportResizeCallback(ViewportSizeCallback);
public:
    App(int width,int height, std::string title);
    ~App();
    
    App(const App&) = delete;
    App(const App&&) = delete;
    App& operator=(App&) = delete;
    App& operator=(App&&) = delete;

    void run();

};

#endif