#include "cylindre.hpp"

Ray Cylindre::GetNormal(const Point &p, const Point &o)
{
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    if ((lo - Point(0, lo[1], 0)).Norm() > 1)
        return localToGlobal(Ray(lp, Vector(lp[0], 0, lp[2]).Normalized()));
    return localToGlobal(Ray(lp, Vector(-lp[0], 0, -lp[2]).Normalized()));
}

bool Cylindre::Intersect(const Ray &ray, Point &impact)
{
    Ray r = globalToLocal(ray);
    r.direction.Normalized();
    float a = r.direction[0] * r.direction[0] + r.direction[2] * r.direction[2];
    float b = 2 * (r.direction[0] * r.origin[0] + r.direction[2] * r.origin[2]);
    float c = r.origin[0] * r.origin[0] + r.origin[2] * r.origin[2] - 1.0;
    float delta = b * b - 4 * a * c;

    if (delta < 0)
        return false;

    float t;
    if (delta < 0.0001)
    {
        t = -b / (2 * a);
    }
    else
    {
        t = (-b - sqrt(delta)) / (2 * a);
        if (t < 0)
            t = (-b + sqrt(delta)) / (2 * a);
    }
    if (t < 0)
        return false;

    Point p = (r.direction * t) + r.origin;
    impact = localToGlobal(p);
    return true;
}