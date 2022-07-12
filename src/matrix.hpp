#pragma once

#include <vector>
#include "hpoint.hpp"
#include "hvector.hpp"

class Matrix
{
private:
    std::vector<std::vector<int>> vect;

public:
    Matrix();
    ~Matrix();
    float operator[](int);
    Matrix Inverse();
    Matrix operator*(HPoint);
    Matrix operator*(HVector);
    Matrix operator*(Matrix);
};
