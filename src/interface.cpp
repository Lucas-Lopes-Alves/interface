#include <glfw/GLFW/glfw3.h>
#include <GL/gl.h>
#include <iostream>

void framebuffer_change(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    std::cout << "Largura: " << width << '\n'
        << "Altura: " << height << '\n';
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

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    while (!glfwWindowShouldClose(janela)){

        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLE_STRIP);
            glColor3f(1.0f, 0.0f, 0.0f); // Vermelho
            glVertex2f(-1.0f, -1.0f);
            
            glColor3f(0.0f, 1.0f, 0.0f); // Verde
            glVertex2f(1.0f, -1.0f);
            
            glColor3f(0.0f, 0.0f, 1.0f); // Azul
            glVertex2f(-1.0f, 1.0f);

            glColor3f(1.0f, 1.0f, 0.0f); // Amarelo
            glVertex2f(1.0f, 1.0f);
        glEnd();

        glfwSwapBuffers(janela);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}