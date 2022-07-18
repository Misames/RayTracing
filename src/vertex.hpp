#include <glm.hpp>

struct Vertex
{
    glm::vec3 position;  //  3x4 octets = 12
    glm::vec3 normal;    // +3x4 octets = 24
    glm::vec2 texcoords; // +2x4 octets = 32

    Vertex(float a, float b, float c)
    {
        position.x = a;
        position.y = b;
        position.z = c;
    }
};