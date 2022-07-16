#include "plan.hpp"

Point Plan::GetTextureCoordinates(const Point &p)
{
    Point lp = globalToLocal(p);
    float x = lp[0] - (int)lp[0];
    float y = lp[1] - (int)lp[1];
    if (x < 0)
        x += 1;
    if (y < 0)
        y += 1;

    return Point(x, y, 0);
}

Ray Plan::GetNormal(const Point &p, const Point &o)
{
    Point lp = globalToLocal(p);
    Point lo = globalToLocal(o);
    float z = 1;
    if (lo[2] < 0)
        z = -1;
    return localToGlobal(Ray(lp, Vector(0, 0, z).Normalized()));
}

bool Plan::Intersec(const Ray &ray, Point &impact)
{

    Ray lr = globalToLocal(ray);
    lr.direction = lr.direction.Normalized();
    if (lr.direction[2] < 0.0001 && lr.direction[2] > -0.0001)
        return false;
    if (lr.direction[2] * lr.origin[2] > 0)
        return false;
    float t = -lr.origin[2] / lr.direction[2];
    Point p = (lr.direction * t) + lr.origin;
    impact = localToGlobal(p);
    return true;
}