#include <GLFW/glfw3.h>
#include <iostream>

void framebuffer_change(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "\r" << "Largura: " << width << ' '
        << "Altura: " << height << " ";
}

int main(int argc, char** argv)
{
    if (!glfwInit())
    {
        std::cerr << "Falha ao inicializar" << "\n";
        return -1;
    }

    GLFWwindow * janela = glfwCreateWindow(500, 500, "Janela", nullptr, nullptr);
    if (!janela)
    {
        std::cerr << "Erro ao criar a janela" << "\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(janela);
    glfwSetFramebufferSizeCallback(janela, framebuffer_change);

    while (!glfwWindowShouldClose(janela)){
        
        glfwSwapBuffers(janela);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}