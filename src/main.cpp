#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#define TINYOBJLOADER_IMPLEMENTATION

#include <iostream>
#include <map>
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <tiny_obj_loader.h>
#include "GLShader.h"
#include "camera.hpp"

using namespace std;
using namespace tinyobj;

struct Object
{
    // Mesh
    attrib_t m_attribs;
    vector<shape_t> m_shapes;
    vector<material_t> m_materials;
    vector<float> m_data;
    string warm, err;
    int m_indexVertex = 0;

    // Texture
    GLuint m_textureId;
    int m_widthTexture, m_heightTexture;

    // Props
    bool m_renderer = true;

    void RenderOpenGL(GLShader m_shader, Camera cam)
    {
        const GLint position = glGetAttribLocation(m_shader.GetProgram(), "a_position");
        glEnableVertexAttribArray(position);
        glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, &m_data[0]);

        const GLint texAttrib = glGetAttribLocation(m_shader.GetProgram(), "a_texcoords");
        glEnableVertexAttribArray(texAttrib);
        glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, &m_data[0]);

        const int normal = glGetAttribLocation(m_shader.GetProgram(), "a_normal");

        static const int stride = sizeof(float) * 8;

        glEnableVertexAttribArray(normal);
        glVertexAttribPointer(normal, 3, GL_FLOAT, false, stride, &m_data[0]);

        glUseProgram(m_shader.GetProgram());

        float time = glfwGetTime();
        const int timeLocation = glGetUniformLocation(m_shader.GetProgram(), "u_time");
        glUniform1f(timeLocation, time);

        float rotationMatrix[] = {
            cosf(time), 0.f, -sinf(time), 0.0f, // 1ere colonne
            0.0f, 1.0f, 0.0f, 0.f,              // 2eme colonne
            sinf(time), 0.f, cosf(time), 0.0f,  // 3eme colonne
            0.0f, 0.0f, 0.0f, 1.0f              // 4eme colonne
        };

        const int rotationLocation = glGetUniformLocation(m_shader.GetProgram(), "u_rotationMatrix");
        glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, rotationMatrix);

        float translationMatrix[] = {
            1.0f, 0.0f, 0.0f, 0.0f,            // 1ere colonne
            0.0f, 1.0f, 0.0f, 0.0f,            // 2eme colonne
            0.0f, 0.0f, 1.0f, 0.0f,            // 3eme colonne
            cosf(time), -100.0f, -350.0f, 1.0f // 4eme colonne
        };

        const int translationLocation = glGetUniformLocation(m_shader.GetProgram(), "u_translationMatrix");
        glUniformMatrix4fv(translationLocation, 1, GL_FALSE, translationMatrix);

        float znear = 0.1f, zfar = 1000.0f, fov = 45.0f;
        cam.Matrix(fov, znear, zfar, m_shader, "u_projectionMatrix");
    }

    Object(string pathObj, string pathMat)
    {
        bool ret = LoadObj(&m_attribs, &m_shapes, &m_materials, &warm, &err, pathObj.c_str(), pathMat.c_str(), true, false);
        if (ret)
        {
            for (auto &shape : m_shapes)
            {
                int index_offset = 0;
                for (int j = 0; j < shape.mesh.num_face_vertices.size(); j++)
                {
                    int fv = shape.mesh.num_face_vertices[j];
                    for (int k = 0; k < fv; k++)
                    {
                        index_t idx = shape.mesh.indices[index_offset + k];
                        m_data.push_back(m_attribs.vertices[3 * idx.vertex_index + 0]);
                        m_data.push_back(m_attribs.vertices[3 * idx.vertex_index + 1]);
                        m_data.push_back(m_attribs.vertices[3 * idx.vertex_index + 2]);

                        if (!m_attribs.normals.empty())
                        {
                            m_data.push_back(m_attribs.normals[3 * idx.normal_index + 0]);
                            m_data.push_back(m_attribs.normals[3 * idx.normal_index + 1]);
                            m_data.push_back(m_attribs.normals[3 * idx.normal_index + 2]);
                        }

                        if (!m_attribs.texcoords.empty())
                        {
                            m_data.push_back(m_attribs.texcoords[2 * idx.texcoord_index + 0]);
                            m_data.push_back(m_attribs.texcoords[2 * idx.texcoord_index + 1]);
                        }
                    }
                    index_offset += fv;
                    m_indexVertex += fv;
                }
            }
            cout << "model load" << endl;
            uint8_t *data = stbi_load("img/brick.png", &m_widthTexture, &m_heightTexture, nullptr, STBI_rgb_alpha);

            glGenTextures(1, &m_textureId);
            glActiveTexture(GL_TEXTURE0);
            glBindTexture(GL_TEXTURE_2D, m_textureId);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

            if (data)
            {
                glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, m_widthTexture, m_heightTexture, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
                glGenerateMipmap(GL_TEXTURE_2D);
                stbi_image_free(data);
            }
        }
        else
            cout << "model not found" << endl;
    }
};

/*
 * Variables Global
 */

GLFWwindow *window;
GLShader m_shader;
bool m_shadows = true;
int m_widthImage, m_heihgtImage;
string nameOutputImage = "default.png";
map<string, int> lstSceneToRender;
vector<Object> lstObj;
Camera cam(640, 480, glm::vec3(0.0f, 0.0f, 2.0f));

void SaveImage(string filepath, GLFWwindow *w)
{
    int width, height;
    glfwGetFramebufferSize(w, &width, &height);
    GLsizei nrChannels = 3;
    GLsizei stride = nrChannels * width;
    stride += (stride % 4) ? (4 - stride % 4) : 0;
    GLsizei bufferSize = stride * height;
    std::vector<char> buffer(bufferSize);
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
    m_shader.LoadVertexShader("vertex.glsl");
    m_shader.LoadFragmentShader("fragment.glsl");
    m_shader.Create();

    // Load Scene
    Object wolf = Object("data/wolf.obj", "");
    Object tree = Object("data/tree.obj", "data/tree.mtl");
    lstObj.push_back(wolf);
    lstObj.push_back(tree);
}

void Shutdown()
{
    m_shader.Destroy();
    glfwTerminate();
}

static void ErrorCallback(int error, const char *description)
{
    cout << "Error GFLW " << error << " : " << description << endl;
}

static void KeyCallback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    if (key == GLFW_KEY_Q && action == GLFW_PRESS)
    {
        // export render into jpg
        cout << "choose name of output image" << endl;
        cin >> nameOutputImage;
        SaveImage(nameOutputImage, window);
        cout << "export rennder" << endl;
    }

    if (key == GLFW_KEY_F10 && action == GLFW_PRESS)
    {
        m_shadows = m_shadows == false ? true : false;
        cout << m_shadows << endl;
    }
}

void Display()
{
    int widthWindow, heightWindow;
    glfwGetWindowSize(window, &widthWindow, &heightWindow);
    glViewport(0, 0, widthWindow, heightWindow);
    glClearColor(0.5f, 0.5f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);

    // exemple d'un model
    lstObj[0].RenderOpenGL(m_shader, cam);

    GLuint basicProgram = m_shader.GetProgram();
    glUseProgram(basicProgram);
    glfwGetWindowSize(window, &widthWindow, &heightWindow);
    glDrawArrays(GL_TRIANGLES, lstObj[0].m_data[0], lstObj[0].m_indexVertex);
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