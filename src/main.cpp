#define STB_IMAGE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <iostream>
#include <map>
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <nlohmann/json.hpp>
#include <stb_image.h>
#include <stb_image_write.h>

#include "GLShader.h"
#include "camera.hpp"
#include "scene.hpp"

using namespace std;

// Global
GLFWwindow *window;
GLuint VAO, VBO;
GLShader shader;
Camera cam(640, 480, glm::vec3(0.0f, 0.0f, 2.0f));
Scene s = Scene();

Object square;
Object triangle = Object();

void SaveImage(string filepath, GLFWwindow *w)
{
    filepath += (string) ".png";
    int width, height;
    glfwGetFramebufferSize(w, &width, &height);

    char rep;
    cout << "Custom size ? y/n" << endl;
    cin >> rep;

    if (rep == 'y')
    {
        cout << "width :";
        cin >> width;
        cout << "height : ";
        cin >> height;
    }

    GLsizei nrChannels = 3;
    GLsizei stride = nrChannels * width;
    stride += (stride % 4) ? (4 - stride % 4) : 0;
    GLsizei bufferSize = stride * height;
    vector<char> buffer(bufferSize);
    glPixelStorei(GL_PACK_ALIGNMENT, 4);
    glReadBuffer(GL_FRONT);
    glReadPixels(0, 0, width, height, GL_RGB, GL_UNSIGNED_BYTE, buffer.data());
    stbi_flip_vertically_on_write(true);
    stbi_write_png(filepath.c_str(), width, height, nrChannels, buffer.data(), stride);
}

void Initialize()
{
    GLenum error = glewInit();
    if (error != GLEW_OK)
        cout << "erreur d'initialisation de GLEW!" << endl;

    // Logs
    cout << "Version : " << glGetString(GL_VERSION) << endl;
    cout << "Vendor : " << glGetString(GL_VENDOR) << endl;
    cout << "Renderer : " << glGetString(GL_RENDERER) << endl;

    // Shader
    shader.LoadVertexShader("vertex.glsl");
    shader.LoadFragmentShader("fragment.glsl");
    shader.Create();

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Scene
    s.backGroundColor = Color(1.0, 0.85, 0.54);
    s.AmbianteColor = Color(1.0f, 1.0f, 1.0f);

    // Square
    Object square = Object(Vector(0.65f, 0.12f, 0.80f));
    // Mesh
    vector<Vertex> vertices;
    vertices.push_back(Vertex(-1.0f, -1.0f, 0.0f));
    vertices.push_back(Vertex(1.0f, -1.0f, 0.0f));
    vertices.push_back(Vertex(-1.0f, 1.0f, 0.0f));
    vertices.push_back(Vertex(-1.0f, 1.0f, 0.0f));
    vertices.push_back(Vertex(1.0f, 1.0f, 0.0f));
    vertices.push_back(Vertex(1.0f, -1.0f, 0.0f));
    square.mesh = vertices;

    // triangle
    vector<Vertex> v2;
    v2.push_back(Vertex(-1.0f + 4, -1.0f + 4, 0.0f));
    v2.push_back(Vertex(1.0f + 4, -1.0f + 4, 0.0f));
    v2.push_back(Vertex(-1.0f + 4, 1.0f + 4, 0.0f));
    triangle.mesh = v2;

    s.listeObject.push_back(square);
    s.listeObject.push_back(triangle);

    for (auto &&i : s.listeObject)
    {
        for (auto &&j : i.mesh)
        {
            // calcule couleur
            cout << "point : " << j.position.x << " " << j.position.y << " " << j.position.z << endl;
        }
    }
}

void Shutdown()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    shader.Destroy();
    glfwTerminate();
}

void ErrorCallback(int error, const char *description)
{
    cout << "Error GFLW " << error << " : " << description << endl;
}

void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    // Exporter rendu
    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        string nameOutputImage;
        cout << "choose name of output image" << endl;
        cin >> nameOutputImage;
        SaveImage(nameOutputImage, window);
        cout << "export rennder..." << endl;
    }
}

void Display()
{
    int widthWindow, heightWindow;
    glfwGetWindowSize(window, &widthWindow, &heightWindow);
    glViewport(0, 0, widthWindow, heightWindow);
    glClearColor(s.backGroundColor.r, s.backGroundColor.g, s.backGroundColor.b, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader.GetProgram());
    cam.Matrix(45.0f, 0.1f, 1000.0f, shader, "u_projection");
    for (auto &&i : s.listeObject)
        i.Render(shader);
}

int main()
{
    glfwSetErrorCallback(ErrorCallback);

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(640, 480, "RayTracing", nullptr, nullptr);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, KeyCallback);
    Initialize();

    while (!glfwWindowShouldClose(window))
    {
        cam.Inputs(window);
        Display();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    Shutdown();
    return 0;
}