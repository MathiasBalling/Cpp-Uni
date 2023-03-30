#include "../Header/rotmat.h"

RotMat2D::RotMat2D() : Matrix(2, 2, 0), angle(0)
{
    at(0, 0) = 1;
    at(1, 1) = 1;
}
RotMat2D::RotMat2D(double angle) : Matrix(2, 2, 0), angle(angle)
{
    at(0, 0) = 1;
    at(1, 1) = 1;
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