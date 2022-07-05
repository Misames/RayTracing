#include "Point.hpp"
#include "Vector.hpp"

class Ray
{
private:
public:
    Point origin;
    Vector vector;
    Ray();
    Ray(const Ray &);
    Ray(Point, Vector);
    Ray(float, float, float, float, float, float);
    ~Ray();
};