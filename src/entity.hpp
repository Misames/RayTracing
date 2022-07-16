#pragma once

#include "matrix.hpp"
#include "ray.hpp"

class Entity
{
public:
    Matrix transform;
    Matrix transformReverse;
    Vector position;

    ~Entity();
    Entity();
    Entity(Matrix);
    Entity(Vector, float, float);

    void translate(float, float, float);
    void rotateX(float);
    void rotateY(float);
    void rotateZ(float);
    void scale(float);

    Vec3 getPosition();
    
    Vector localToGlobal(Vector);
    Point localToGlobal(Point);
    Ray localToGlobal(Ray);
    Point globalToLocal(Point);
    Vector globalToLocal(Vector);
    Ray globalToLocal(Ray);
};