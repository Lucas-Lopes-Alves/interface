#ifndef APP_CLASS
#define APP_CLASS

// #include "glad/gl.h"
// #include "glFunc.hpp"
#include <GLFW/glfw3.h>
#include "wrapper.hpp"
#include "elements/baseObject.hpp"
#include <string>
#include <vector>


class App{
private:
    WindowConfig global;
    Window mainWindow;
    std::vector<baseObject> children;
    
    void ViewportResizeCallback(GLFWframebuffersizefun);
public:
    App(int width,int height, std::string title);
    ~App();
    
    App(const App&) = delete;
    App(const App&&) = delete;
    App& operator=(App&) = delete;
    App& operator=(App&&) = delete;

    void run();

    virtual void setElements() = 0;

    void addButton(baseObject object);

    void render();
};

#endif