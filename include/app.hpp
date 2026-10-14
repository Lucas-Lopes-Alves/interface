#ifndef APP_CLASS__
#define APP_CLASS__

#include "renderer.hpp"
#include <GLFW/glfw3.h>
#include "wrapper.hpp"
#include "elements/baseObject.hpp"
#include <algorithm>
#include <memory>
#include <string>
#include <vector>

enum class backgroundColors{
    
};

template <typename T>
concept Object = requires (T obj) {
    obj.setPosition(0.0f,0.0f);
    obj.setSize(0.0f ,0.0f);

    obj.getPosition();
    obj.getSize();

    obj.getStyle();
    
};

class App{
private:
    friend void mouseCallback(GLFWwindow* window, int button, int action, int mods);
    
    WindowConfig global;
    Window mainWindow;
    Renderer loader;
    float windowX;
    float windowY;
    std::vector<std::unique_ptr<BaseObject>> childrenElements;
    
    void onResize(int width, int height);
    void render();
    static void sizeCallback (GLFWwindow* window, int width, int height);
public:
    App(int width,int height, std::string title);
    virtual ~App() = default;
    
    App(const App&) = delete;
    App(const App&&) = delete;
    App& operator=(App&) = delete;
    App& operator=(App&&) = delete;

    void run();

    template<Object T>
    T& createElement(){
        auto object = std::make_unique<T>();
        T& reference = *object;
        childrenElements.emplace_back(std::move(object));
        return reference;
    }

    void setBackgroundColor();
};

#endif