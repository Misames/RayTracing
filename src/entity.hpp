#pragma once

#include "matrix.hpp"
#include "ray.hpp"

class Entity
{
public:
    Matrix transform;
    Matrix transformReverse;
    Point position;

    ~Entity();
    Entity(Matrix);
    Entity(Vector, float, float);

    void translate(float, float, float);
    void rotateX(float);
    void rotateY(float);
    void rotateZ(float);
    void scale(float);
    Vector localToGlobal(Vector);
    Point localToGlobal(Point);
    Ray localToGlobal(Ray);
    Point globalToLocal(Point);
    Vector globalToLocal(Vector);
    Ray globalToLocal(Ray);
};