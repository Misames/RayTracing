#include "object.hpp"

Object::~Object() {}

Object::Object() : Entity() {}

Object::Object(Vector trans, float rot, float scal, Material mate) : Entity(trans, rot, scal), mat(mate) {}

Material Object::GetMaterial(const Point &p)
{
    return this->mat;
}
