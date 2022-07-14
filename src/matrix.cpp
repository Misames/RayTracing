#include "matrix.hpp"

Matrix::~Matrix() {}

Matrix::Matrix() : mat({0}) {}

Matrix::Matrix(array<array<float, 4>, 4> mat)
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            this->mat[i][j] = mat[i][j];
    }
}

/**
 *
 * Return a matrix null
 * to-do : fix it
 */
Matrix Matrix::Reverse()
{
    Matrix reverseMat;

    float A2323 = this->mat[2][2] * this->mat[3][3] - this->mat[2][3] * this->mat[3][2];
    float A1323 = this->mat[2][1] * this->mat[3][3] - this->mat[2][3] * this->mat[3][1];
    float A1223 = this->mat[2][1] * this->mat[3][2] - this->mat[2][2] * this->mat[3][1];
    float A0323 = this->mat[2][0] * this->mat[3][3] - this->mat[2][3] * this->mat[3][0];
    float A0223 = this->mat[2][0] * this->mat[3][2] - this->mat[2][2] * this->mat[3][0];
    float A0123 = this->mat[2][0] * this->mat[3][1] - this->mat[2][1] * this->mat[3][0];
    float A2313 = this->mat[1][2] * this->mat[3][3] - this->mat[1][3] * this->mat[3][2];
    float A1313 = this->mat[1][1] * this->mat[3][3] - this->mat[1][3] * this->mat[3][1];
    float A1213 = this->mat[1][1] * this->mat[3][2] - this->mat[1][2] * this->mat[3][1];
    float A2312 = this->mat[1][2] * this->mat[2][3] - this->mat[1][3] * this->mat[2][2];
    float A1312 = this->mat[1][1] * this->mat[2][3] - this->mat[1][3] * this->mat[2][1];
    float A1212 = this->mat[1][1] * this->mat[2][2] - this->mat[1][2] * this->mat[2][1];
    float A0313 = this->mat[1][0] * this->mat[3][3] - this->mat[1][3] * this->mat[3][0];
    float A0213 = this->mat[1][0] * this->mat[3][2] - this->mat[1][2] * this->mat[3][0];
    float A0312 = this->mat[1][0] * this->mat[2][3] - this->mat[1][3] * this->mat[2][0];
    float A0212 = this->mat[1][0] * this->mat[2][2] - this->mat[1][2] * this->mat[2][0];
    float A0113 = this->mat[1][0] * this->mat[3][1] - this->mat[1][1] * this->mat[3][0];
    float A0112 = this->mat[1][0] * this->mat[2][1] - this->mat[1][1] * this->mat[2][0];

    float det = this->mat[0][0] * (this->mat[1][1] * A2323 - this->mat[1][2] * A1323 + this->mat[1][3] * A1223) - this->mat[0][1] * (this->mat[1][0] * A2323 - this->mat[1][2] * A0323 + this->mat[1][3] * A0223) + this->mat[0][2] * (this->mat[1][0] * A1323 - this->mat[1][1] * A0323 + this->mat[1][3] * A0123) - this->mat[0][3] * (this->mat[1][0] * A1223 - this->mat[1][1] * A0223 + this->mat[1][2] * A0123);
    det = 1 / det;

    reverseMat.mat[0][0] = det * (this->mat[1][1] * A2323 - this->mat[1][2] * A1323 + this->mat[1][3] * A1223);
    reverseMat.mat[0][1] = det * -(this->mat[0][1] * A2323 - this->mat[0][2] * A1323 + this->mat[0][3] * A1223);
    reverseMat.mat[0][2] = det * (this->mat[0][1] * A2313 - this->mat[0][2] * A1313 + this->mat[0][3] * A1213);
    reverseMat.mat[0][3] = det * -(this->mat[0][1] * A2312 - this->mat[0][2] * A1312 + this->mat[0][3] * A1212);
    reverseMat.mat[1][0] = det * -(this->mat[1][0] * A2323 - this->mat[1][2] * A0323 + this->mat[1][3] * A0223);
    reverseMat.mat[1][1] = det * (this->mat[0][0] * A2323 - this->mat[0][2] * A0323 + this->mat[0][3] * A0223);
    reverseMat.mat[1][2] = det * -(this->mat[0][0] * A2313 - this->mat[0][2] * A0313 + this->mat[0][3] * A0213);
    reverseMat.mat[1][3] = det * (this->mat[0][0] * A2312 - this->mat[0][2] * A0312 + this->mat[0][3] * A0212);
    reverseMat.mat[2][0] = det * (this->mat[1][0] * A1323 - this->mat[1][1] * A0323 + this->mat[1][3] * A0123);
    reverseMat.mat[2][1] = det * -(this->mat[0][0] * A1323 - this->mat[0][1] * A0323 + this->mat[0][3] * A0123);
    reverseMat.mat[2][2] = det * (this->mat[0][0] * A1313 - this->mat[0][1] * A0313 + this->mat[0][3] * A0113);
    reverseMat.mat[2][3] = det * -(this->mat[0][0] * A1312 - this->mat[0][1] * A0312 + this->mat[0][3] * A0112);
    reverseMat.mat[3][0] = det * -(this->mat[1][0] * A1223 - this->mat[1][1] * A0223 + this->mat[1][2] * A0123);
    reverseMat.mat[3][1] = det * (this->mat[0][0] * A1223 - this->mat[0][1] * A0223 + this->mat[0][2] * A0123);
    reverseMat.mat[3][2] = det * -(this->mat[0][0] * A1213 - this->mat[0][1] * A0213 + this->mat[0][2] * A0113);
    reverseMat.mat[3][3] = det * (this->mat[0][0] * A1212 - this->mat[0][1] * A0212 + this->mat[0][2] * A0112);

    return reverseMat;
}

void Matrix::operator=(const Matrix &m)
{
    this->mat = m.mat;
}

Matrix Matrix::operator*(const Matrix &m)
{
    Matrix ret;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ret.mat[i][j] = 0;
            for (int k = 0; k < 4; k++)
            {
                ret.mat[i][j] += this->mat[i][k] * (m.mat[k][j]);
            }
        }
    }
    return ret;
}

HPoint Matrix::operator*(const HPoint &p)
{
    HPoint ret;
    ret.x = (this->mat[0][0] * p.x) + (this->mat[0][1] * p.y) + (this->mat[0][2] * p.z) + (this->mat[0][3] * p.w);
    ret.y = (this->mat[1][0] * p.x) + (this->mat[1][1] * p.y) + (this->mat[1][2] * p.z) + (this->mat[1][3] * p.w);
    ret.z = (this->mat[2][0] * p.x) + (this->mat[2][1] * p.y) + (this->mat[2][2] * p.z) + (this->mat[2][3] * p.w);
    ret.w = (this->mat[3][0] * p.x) + (this->mat[3][1] * p.y) + (this->mat[3][2] * p.z) + (this->mat[3][3] * p.w);
    return ret;
}

HVector Matrix::operator*(const HVector &v)
{
    HVector vec;
    vec.x = (this->mat[0][0] * v.x) + (this->mat[0][1] * v.y) + (this->mat[0][2] * v.z) + (this->mat[0][3] * v.w);
    vec.y = (this->mat[1][0] * v.x) + (this->mat[1][1] * v.y) + (this->mat[1][2] * v.z) + (this->mat[1][3] * v.w);
    vec.z = (this->mat[2][0] * v.x) + (this->mat[2][1] * v.y) + (this->mat[2][2] * v.z) + (this->mat[2][3] * v.w);
    vec.w = (this->mat[3][0] * v.x) + (this->mat[3][1] * v.y) + (this->mat[3][2] * v.z) + (this->mat[3][3] * v.w);
    return vec;
}
