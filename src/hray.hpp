#pragma once

#include "ray.hpp"
#include "hpoint.hpp"
#include "hvector.hpp"

class HRay : public Ray
{
public:
    HPoint origin;
    HVector direction;

    ~HRay();
    HRay();
    HRay(HPoint, HVector);
    HRay(float, float, float, float, float, float);
};
