#include "entity.hpp"

Entity::Entity()
{
}

Entity::~Entity()
{
}

void Entity::translate(float x, float y, float z)
{
}

void Entity::rotateX(float deg)
{
}

void Entity::rotateY(float deg)
{
}

void Entity::rotateZ(float deg)
{
}

void Entity::scale(float factor)
{
}

Vector Entity::localToGlobal(const Vector &v) const
{
    return Vector();
}

Point Entity::localToGlobal(const Point &p) const
{
    return Point();
}

Ray Entity::localToGlobal(const Ray &r) const
{
    return Ray();
}