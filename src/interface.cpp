// #include "glad/gl.h"
#include <GL/gl.h>
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
    
    Window janela(1920/2,1080/2, std::string("Ola"));

    global.loadOpenGL();
    janela.setFramebufferSizeCallback(framebuffer_change);

    while (!janela.windowShouldClose()){
        global.pollEvents();
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glBegin(GL_LINES);
            glVertex2f(-0.1f, 0.1f);
            glVertex2f(0.1f, 0.1f);

            glVertex2f(0.1f, 0.1f);
            glVertex2f(0.1f, -0.1f);

            glVertex2f(-0.1f, 0.1f);
            glVertex2f(-0.1f, -0.1f);
            
            glVertex2f(0.1f, -0.1f);
            glVertex2f(-0.1f, -0.1f);
        glEnd();
        
        janela.swapBuffers();
    }
    return 0;
}