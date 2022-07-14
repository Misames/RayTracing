#pragma once

#include <array>
#include "hpoint.hpp"
#include "hvector.hpp"

using namespace std;

class Matrix
{
public:
    array<array<float, 4>, 4> mat;

    ~Matrix();
    Matrix();
    Matrix(const array<array<float, 4>, 4>);

    void operator=(const Matrix &);
    HPoint operator*(const HPoint &);
    HVector operator*(const HVector &);
    Matrix operator*(const Matrix &);

    Matrix Reverse();
};
