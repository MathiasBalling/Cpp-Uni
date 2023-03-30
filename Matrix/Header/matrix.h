#pragma once
#include <iostream>
#include <vector>

class Matrix
{
public:
    Matrix(int rows, int cols, double val = 0.0);
    int getRows();
    int getCols();
    virtual void print();
    double &at(int r, int c);
    Matrix add(Matrix matrix);
    Matrix multiply(Matrix matrix);
    virtual void transpose();
    double &operator()(int r, int c);
    Matrix operator+(Matrix m);
    Matrix operator*(Matrix m);
    Matrix operator*(double v);

private:
    int rows, cols;
    std::vector<double> m_data;
};
