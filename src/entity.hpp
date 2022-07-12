#pragma once

#include "vector.hpp"
#include "point.hpp"
#include "ray.hpp"

class Entity
{
private:
public:
    Entity();
    ~Entity();
    void translate(float x, float y, float z);
    void rotateX(float deg);
    void rotateY(float deg);
    void rotateZ(float deg);
    void scale(float factor);
    Vector localToGlobal(const Vector &v) const;
    Point localToGlobal(const Point &p) const;
    Ray localToGlobal(const Ray &r) const;
};