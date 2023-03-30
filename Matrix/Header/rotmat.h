#pragma once
#include "matrix.h"

class RotMat2D : public Matrix
{
public:
    RotMat2D();
    RotMat2D(double angle);
    void print() override;
    void transpose() override;

private:
    double angle;
};