#include "wrapper.hpp"
#include <iostream>

void framebuffer_change(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "\r" << "Largura: " << width << ' '
        << "Altura: " << height << " ";
}

int main(int argc, char** argv)
{

    GlobalWindow global;
    
    Window janela(200,200, std::string("Ola"));

    janela.MakeContextCurrent();
    janela.setFramebufferSizeCallback(framebuffer_change);

    while (!janela.WindowShouldClose()){
        
        janela.SwapBuffers();
        global.PollEvents();
    }
    return 0;
}