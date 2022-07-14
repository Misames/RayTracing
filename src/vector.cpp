#include "vector.hpp"

Vector::~Vector() {}

Vector::Vector() : x(.0f), y(.0f), z(.0f), w(.0f) {}

Vector::Vector(const Vector &v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

Vector::Vector(float a, float b) : x(a), y(b), z(0.f), w(0.f) {}

Vector::Vector(float a, float b, float c) : x(a), y(b), z(c), w(0.f) {}

Vector::Vector(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}

void Vector::operator=(const Vector &v)
{
    this->x = v.x;
    this->y = v.y;
    this->z = v.z;
    this->w = v.w;
}

Vector Vector::operator+(Vector v)
{
    this->x += v.x;
    this->y += v.y;
    this->z += v.z;
    this->w += v.w;
    return *this;
}

Vector Vector::operator-(Vector v)
{
    this->x -= v.x;
    this->y -= v.y;
    this->z -= v.z;
    this->w -= v.w;
    return *this;
}
Vector Vector::operator*(float a)
{
    this->x *= a;
    this->y *= a;
    this->z *= a;
    this->w *= a;
    return *this;
}

Vector Vector::operator/(float a)
{
    this->x /= a;
    this->y /= a;
    this->z /= a;
    this->w /= a;
    return *this;
}

Vector Vector::Opposite()
{
    Vector ret;
    ret.x = -this->x;
    ret.y = -this->y;
    ret.z = -this->z;
    ret.w = -this->w;
    return ret;
}

Vector Vector::Normalized()
{
    Vector vecRet;
    vecRet.x = this->x / fabsf(this->x);
    vecRet.y = this->y / fabsf(this->y);
    vecRet.z = this->z / fabsf(this->z);
    vecRet.w = this->w / fabsf(this->w);
    return vecRet;
}

float Vector::Norm()
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2) + pow(this->w, 2));
}

float Vector::Dot(Vector vec)
{
    return this->x * vec.x + this->y * vec.y + this->z * vec.z + this->w * vec.w;
}