#include <glfw/GLFW/glfw3.h>
#include <string>
#include <iostream>

class Window{
    int m_width;
    int m_height;
    std::string m_title;
    GLFWwindow* handler;
    
    public:
        Window(int width,int height, const std::string& title)
        : m_width(width), m_height(height), m_title(title){
            if (!glfwInit()) {
                std::cerr << "Error creating the window" <<'\n';
                return;
            }

            this->handler = glfwCreateWindow(m_width, m_height, m_title.c_str(), nullptr, nullptr);
        }
};