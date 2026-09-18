#ifndef APP_CLASS__
#define APP_CLASS__

// #include "glad/gl.h"
// #include "glFunc.hpp"
#include "renderer.hpp"
#include <GLFW/glfw3.h>
#include "wrapper.hpp"
#include "elements/baseObject.hpp"
#include <string>
#include <vector>


class App{
private:
    WindowConfig global;
    Window mainWindow;
    Renderer loader;
    std::vector<baseObject> childrenElements;
    
    void ViewportResizeCallback(GLFWframebuffersizefun);
public:
    App(int width,int height, std::string title);
    virtual ~App() = default;
    
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