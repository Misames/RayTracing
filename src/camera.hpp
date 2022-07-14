#pragma once


#include "includes/glew/glew.h"
#include "includes/glfw/glfw3.h"
#include "includes/glm/glm.hpp"

#include "includes/glm/gtc/matrix_transform.hpp"
#include "includes/glm/gtc/type_ptr.hpp"
#include "includes/glm/gtx/rotate_vector.hpp"
#include "includes/glm/gtx/vector_angle.hpp"


#include "includes/GLShader.h"
class Camera
{
public:
    // Stores the main vectors of the camera
    glm::vec3 Position;
    glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

    // Prevents the camera from jumping around when first clicking left click
    bool firstClick = true;

    // Stores the width and height of the window
    int width;
    int height;

    // Adjust the speed of the camera and it's sensitivity when looking around
    float speed = 1.5f;
    float sensitivity = 100.0f;

    // Camera constructor to set up initial values
    Camera(int width, int height, glm::vec3 position);

    // Updates and exports the camera matrix to the Vertex Shader
    void Matrix(float FOVdeg, float nearPlane, float farPlane, GLShader &shader, const char *uniform);

    // Handles camera inputs
    void Inputs(GLFWwindow *window);
};
