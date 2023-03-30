#include "rotmat.h"
#include <cmath>

RotMat2D::RotMat2D() : Matrix(2, 2, 0)
{
    at(0, 0) = 1;
    at(1, 1) = 1;
}
RotMat2D::RotMat2D(double angle) : Matrix(2, 2, 0), angle(angle)
{
    at(0, 0) = cos(angle);
    at(0, 1) = -sin(angle);
    at(1, 0) = sin(angle);
    at(1, 1) = cos(angle);
}

void RotMat2D::print()
{
    Matrix::print();
    std::cout << "Angle: " << angle << std::endl;
}

void RotMat2D::transpose()
{
    Matrix::transpose();
    angle = -angle;
}