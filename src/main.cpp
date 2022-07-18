#define STB_IMAGE_IMPLEMENTATION
#define STBI_MSC_SECURE_CRT
#define STB_IMAGE_WRITE_IMPLEMENTATION
#define TINYOBJLOADER_IMPLEMENTATION

#include <iostream>
#include <map>
#include <glew.h>
#include <glfw3.h>
#include <glm.hpp>
#include <tiny_obj_loader.h>
#include "stb_image.h"
#include "stb_image_write.h"
#include "GLShader.h"

#include "camera.hpp"
#include "point.hpp"
#include "hpoint.hpp"
#include "vector.hpp"
#include "hvector.hpp"
#include "matrix.hpp"
#include "ray.hpp"
#include "hray.hpp"
#include "entity.hpp"
#include "scene.hpp"

using namespace std;
using namespace tinyobj;

struct SubObject
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
        if (!m_renderer)
            return;

        static const int stride = sizeof(float) * 8;

        const GLint position = glGetAttribLocation(m_shader.GetProgram(), "a_position");
        glEnableVertexAttribArray(position);
        glVertexAttribPointer(position, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, &m_data[0]);

        const GLint texAttrib = glGetAttribLocation(m_shader.GetProgram(), "a_texcoords");
        glEnableVertexAttribArray(texAttrib);
        glVertexAttribPointer(texAttrib, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, &m_data[0]);

        const int normal = glGetAttribLocation(m_shader.GetProgram(), "a_normal");
        glEnableVertexAttribArray(normal);
        glVertexAttribPointer(normal, 3, GL_FLOAT, false, stride, &m_data[0]);

        float time = glfwGetTime();
        const int timeLocation = glGetUniformLocation(m_shader.GetProgram(), "u_time");
        glUniform1f(timeLocation, time);

        float translation[] = {
            1.0f, 0.0f, 0.0f, 0.0f,            // 1ere colonne
            0.0f, 1.0f, 0.0f, 0.0f,            // 2eme colonne
            0.0f, 0.0f, 1.0f, 0.0f,            // 3eme colonne
            cosf(time), -100.0f, -350.0f, 1.0f // 4eme colonne
        };

        const int translationLocation = glGetUniformLocation(m_shader.GetProgram(), "u_translation");
        glUniformMatrix4fv(translationLocation, 1, GL_FALSE, translation);

        float rotation[] = {
            cosf(time), 0.f, -sinf(time), 0.0f, // 1ere colonne
            0.0f, 1.0f, 0.0f, 0.f,              // 2eme colonne
            sinf(time), 0.f, cosf(time), 0.0f,  // 3eme colonne
            0.0f, 0.0f, 0.0f, 1.0f              // 4eme colonne
        };

        const int rotationLocation = glGetUniformLocation(m_shader.GetProgram(), "u_rotation");
        glUniformMatrix4fv(rotationLocation, 1, GL_FALSE, rotation);

        float scale[] = {
            1.0f, 0.0f, 0.0f, 0.0f, // 1ere colonne
            0.0f, 1.0f, 0.0f, 0.0f, // 2eme colonne
            0.0f, 0.0f, 1.0f, 0.0f, // 3eme colonne
            0.0f, 0.0f, 0.0f, 1.0f  // 4eme colonne
        };

        const int scaleLocation = glGetUniformLocation(m_shader.GetProgram(), "u_scale");
        glUniformMatrix4fv(scaleLocation, 1, GL_FALSE, scale);

        cam.Matrix(45.0f, 0.1f, 1000.0f, m_shader, "u_projection");

        glDrawArrays(GL_TRIANGLES, m_data[0], m_indexVertex);
    }

    SubObject(string pathObj, string pathMat)
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
        }
        else
        {
            cout << "model not found" << endl;
        }
    }
};

// Global
GLFWwindow *window;
GLShader shader;
bool shadows = true;
int widthImage, heihgtImage;
string nameOutputImage = "default.png";
map<string, int> lstSceneToRender;
vector<SubObject> lstObj;
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
    shader.LoadVertexShader("vertex.glsl");
    shader.LoadFragmentShader("fragment.glsl");
    shader.Create();

    // Load Scene
    SubObject wolf = SubObject("data/wolf.obj", "");
    SubObject tree = SubObject("data/tree.obj", "data/tree.mtl");
    lstObj.push_back(wolf);
    lstObj.push_back(tree);
}

void Shutdown()
{
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
        cout << "choose name of output image" << endl;
        cin >> nameOutputImage;
        SaveImage(nameOutputImage, window);
        cout << "export rennder" << endl;
    }

    // Activer/Désactiver les ombres
    if (key == GLFW_KEY_F10 && action == GLFW_PRESS)
    {
        shadows = shadows ? false : true;
        cout << "Shadows : " << noboolalpha << shadows << endl;
    }

    // Afficher/Cacher wolf
    if (key == GLFW_KEY_F9 && action == GLFW_PRESS)
    {
        lstObj[0].m_renderer = lstObj[0].m_renderer ? false : true;
        cout << "Rendu : " << noboolalpha << lstObj[0].m_renderer << endl;
    }
}

void Display()
{
    int widthWindow, heightWindow;
    glfwGetWindowSize(window, &widthWindow, &heightWindow);
    glClearColor(0.5f, 0.5f, 0.5f, 1.f);
    glClear(GL_COLOR_BUFFER_BIT);
    glUseProgram(shader.GetProgram());

    // exemple d'un model
    for (auto &&obj : lstObj)
        obj.RenderOpenGL(shader, cam);
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
    Scene mainScene("bin/data/test.json");
 
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