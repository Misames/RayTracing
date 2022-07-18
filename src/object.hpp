#pragma once

#include <vector>
#include <glew.h>
#include <glfw3.h>
#include "GLShader.h"
#include "entity.hpp"
#include "material.hpp"
#include "vertex.hpp"
#include "vector.hpp"
#include "ray.hpp"

using namespace std;

class Object : public Entity
{
public:
    vector<Material> mats;
    vector<Vertex> mesh;
    Vector baseColor;
    bool render = true;

    ~Object();
    Object();
    Object(Vector);
    Object(Vector, float, float, vector<Material>);

    void Render(GLShader);
    Material GetMaterial(const Point &);
    // Fonction surchargé dans les différents Objets, initialisé par default pour un plan
    virtual Point getTextureCoordinates(const Point &);
    virtual Ray getNormal(const Point &, const Point &);
    virtual bool intersect(const Ray &, Point &);
};
