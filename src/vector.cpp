#include "vector.hpp"

Vector::~Vector() {}

Vector::Vector() : x(.0f), y(.0f), z(.0f), w(.0f) {}

Vector::Vector(const Vector &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

Vector::Vector(float a, float b) : x(a), y(b), z(0.f), w(0.f) {}

Vector::Vector(float a, float b, float c) : x(a), y(b), z(c), w(0.f) {}

Vector::Vector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}

Vector &Vector::operator*(const float a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;
    return *this;
}

Vector &Vector::operator+=(const float a)
{
    this->x += a;
    this->y += a;
    this->z += a;
    return *this;
}

Vector &Vector::operator-=(const float a)
{
    this->x -= a;
    this->y -= a;
    this->z -= a;
    return *this;
}

Vector &Vector::operator/=(const float a)
{
    this->x /= a;
    this->y /= a;
    this->z /= a;
    return *this;
}

Vector &Vector::operator+(const Point p)
{
    this->x = this->x + p.x;
    this->y = this->y + p.y;
    this->z = this->z + p.z;
    return *this;
}

float &Vector::operator[](const int i)
{
    if (i == 0)
        return this->x;

    if (i == 1)
        return this->y;

    if (i == 2)
        return this->z;
}

float Vector::operator[](const int i) const
{
    if (i == 0)
        return this->x;

    if (i == 1)
        return this->y;

    if (i == 2)
        return this->z;
}

Vector Vector::Normalized()
{
    Vector vecRet;
    vecRet.x = this->x / fabsf(this->x);
    vecRet.y = this->y / fabsf(this->y);
    vecRet.z = this->z / fabsf(this->z);
    return vecRet;
}

float Vector::Norm()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}

float Vector::Dot(Vector vec)
{
    return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}
float Vector::Dot(Point vec)
{
    return this->x * vec.x + this->y * vec.y + this->z * vec.z;
}

Vector Vector::Opposite()
{
    Vector ret;
    ret.x = -this->x;
    ret.y = -this->y;
    ret.z = -this->z;
    return ret;
}
