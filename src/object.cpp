#include "object.hpp"
using namespace std;

Object::~Object() {}

Object::Object() : Entity() {}

Object::Object(Vector baseColor) : Entity(), baseColor(baseColor) {}

void Object::Render(GLShader shader)
{
    if (!render)
        return;

    constexpr int STRIDE = sizeof(Vertex);
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, STRIDE * this->mesh.size(), this->mesh.data(), GL_STATIC_DRAW);

    const int POSITION = glGetAttribLocation(shader.GetProgram(), "a_position");
    glEnableVertexAttribArray(POSITION);
    glVertexAttribPointer(POSITION, 3, GL_FLOAT, GL_TRUE, STRIDE, (void *)offsetof(Vertex, position));

    const int colorLocation = glGetUniformLocation(shader.GetProgram(), "u_color");
    glUniform4f(colorLocation, baseColor.x, baseColor.y, baseColor.z, 1.0f);

    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glDrawArrays(GL_TRIANGLES, 0, this->mesh.size());
}

Object::Object(Vector trans, float rot, float scal, vector<Material> mate) : Entity(trans, rot, scal), mats(mate) {}

Material Object::GetMaterial(const Point &p)
{
    Point lp = globalToLocal(p);
    // on check si l'objet a plusieurs matérials
    // Si oui si la coordonée en X est pair on prend le premier mat sinon on prend le deuxieme
    if (this->mats.size() > 1)
    {
        if (((int)lp.x * 10) % 2 == 0)
            return mats[0];
        else
            return mats[1];
    }
    return mats[0];
}

Point Object::getTextureCoordinates(const Point &p)
{
    Point lp = globalToLocal(p);
    float x = lp[0] - (int)lp[0];
    float y = lp[1] - (int)lp[1];
    if (x < 0)
        x += 1;
    if (y < 0)
        y += 1;

    return Point(x, y, 0);
}

Ray Object::getNormal(const Point &p, const Point &o)
{
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    float z = 1;
    if (lo[2] < 0)
        z = -1;
    return localToGlobal(Ray(lp, Vector(0, 0, z).Normalized()));
}

bool Object::intersect(const Ray &ray, Point &impact)
{
    Ray lr = globalToLocal(ray);
    lr.direction = lr.direction.Normalized();
    if (lr.direction[2] < 0.0001 && lr.direction[2] > -0.0001)
        return false;
    if (lr.direction[2] * lr.origin[2] > 0)
        return false;
    float t = -lr.origin[2] / lr.direction[2];
    Point p = (lr.direction * t) + lr.origin;
    impact = localToGlobal(p);
    return true;
}
