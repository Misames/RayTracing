#include <iostream>
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include "GLShader.h"

GLShader myShader;

void Initialize()
{
    GLenum error = glewInit();
    if (error != GLEW_OK)
        std::cout << "erreur d'initialisation de GLEW!" << std::endl;

    // Logs
    std::cout << "Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "Vendor : " << glGetString(GL_VENDOR) << std::endl;
    std::cout << "Renderer : " << glGetString(GL_RENDERER) << std::endl;

    // Shader
    myShader.LoadVertexShader("vertex.glsl");
    myShader.LoadFragmentShader("fragment.glsl");
    myShader.Create();
}

void Shutdown()
{
    myShader.Destroy();
    glfwTerminate();
}

void Display(GLFWwindow *window)
{
    int width, height;
    glfwGetWindowSize(window, &width, &height);
    glViewport(0, 0, width, height);

    glClearColor(0.5f, 0.5f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    GLuint basicProgram = myShader.GetProgram();
    glUseProgram(basicProgram);
}

static void error_callback(int error, const char *description)
{
    std::cout << "Error GFLW " << error << " : " << description << std::endl;
}

static void key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

int main(void)
{
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "RayTracing", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
    Initialize();

    while (!glfwWindowShouldClose(window))
    {
        Display(window);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Shutdown();
    return 0;
}