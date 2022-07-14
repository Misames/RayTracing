#include "entity.hpp"

Entity::~Entity() {}

Entity::Entity(Matrix mat)
{
    transform.mat = mat.mat;
    transformReverse = mat.Reverse();
}

void Entity::translate(float x, float y, float z)
{
    Matrix m;
    m.mat[0][3] += x;
    m.mat[1][3] += y;
    m.mat[2][3] += z;
    this->transform = m * this->transform;
    this->transformReverse = this->transformReverse.Reverse();
}

Entity::Entity(Vector translation, float rotation, float scaling)
{

    translate(translation.x, translation.y, translation.z);
    rotateX(rotation);
    rotateY(rotation);
    rotateZ(rotation);
    scale(scaling);
}

void Entity::rotateX(float deg)
{
    Matrix m;
    float rad = deg * M_PI / 180;
    m.mat[1][1] = cos(rad);
    m.mat[1][2] = -sin(rad);
    m.mat[2][1] = sin(rad);
    m.mat[2][2] = cos(rad);
    this->transform = m * this->transform;
    this->transformReverse = this->transformReverse.Reverse();
}

void Entity::rotateY(float deg)
{
    Matrix m;
    float rad = deg * M_PI / 180;
    m.mat[0][0] = cos(rad);
    m.mat[0][2] = sin(rad);
    m.mat[2][0] = -sin(rad);
    m.mat[2][2] = cos(rad);
    this->transform = m * this->transform;
    this->transformReverse = this->transformReverse.Reverse();
}

void Entity::rotateZ(float deg)
{
    Matrix m;
    float rad = deg * M_PI / 180;
    m.mat[0][0] = cos(rad);
    m.mat[0][1] = -sin(rad);
    m.mat[1][0] = sin(rad);
    m.mat[1][1] = cos(rad);
    this->transform = m * this->transform;
    this->transformReverse = this->transformReverse.Reverse();
}

void Entity::scale(float factor)
{
    Matrix m;
    m.mat[0][0] = factor;
    m.mat[1][1] = factor;
    m.mat[2][2] = factor;
    this->transform = m * this->transform;
    this->transformReverse = this->transformReverse.Reverse();
}

Point Entity::localToGlobal(Point p)
{
    HPoint hpo = HPoint(p.x, p.y, p.z);
    HPoint tmp = this->transformReverse * hpo;
    Point ret(tmp.x, tmp.y, tmp.z);
    return ret;
}

Vector Entity::localToGlobal(Vector v)
{
    HVector hvect = HVector(v.x, v.y, v.z);
    HVector tmp = (this->transformReverse * hvect);
    Vector ret(tmp.x, tmp.y, tmp.z);
    return ret;
}

Ray Entity::localToGlobal(Ray r)
{
    // Convertion de l'origin
    HPoint rorigin = HPoint(r.origin.x, r.origin.y, r.origin.z);
    HPoint retOr = this->transformReverse * rorigin;
    Point pointOrigin(retOr.x, retOr.y, retOr.z);

    // convertion du vecteur directeur
    HVector rdir(r.direction.x, r.direction.y, r.direction.z);
    HVector retDir = this->transformReverse * rdir;
    Vector vectDirecteur(retDir.x, retDir.y, retDir.z);

    return Ray(pointOrigin, vectDirecteur);
}

Point Entity::globalToLocal(Point p)
{
    HPoint hpo = HPoint(p.x, p.y, p.z);
    HPoint tmp = (this->transform * hpo);
    Point ret(tmp.x, tmp.y, tmp.z);
    return ret;
}

Vector Entity::globalToLocal(Vector v)
{
    HVector hvect = HVector(v.x, v.y, v.z);
    HVector tmp = (this->transform * hvect);
    HVector ret(tmp.x, tmp.y, tmp.z);
    return ret;
}

Ray Entity::globalToLocal(Ray r)
{
    // Convertion de l'origin
    HPoint rorigin = HPoint(r.origin.x, r.origin.y, r.origin.z);
    HPoint retOr = this->transform * rorigin;
    Point pointOrigin(retOr.x, retOr.y, retOr.z);

    // convertion du vecteur directeur
    HVector rdir = HVector(r.direction.x, r.direction.y, r.direction.z);
    HVector retDir = this->transform * rdir;
    Vector vectDirecteur(retDir.x, retDir.y, retDir.z);

    return Ray(pointOrigin, vectDirecteur);
}
