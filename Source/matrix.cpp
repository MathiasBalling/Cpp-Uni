#include "../Header/matrix.h"

Matrix::Matrix(int rows, int cols, double val) : cols(cols), rows(rows)
{

    for (int i = 0; i < (rows * cols); i++)
    {
        m_data.push_back(val);
    }
}

int Matrix::getRows()
{
    return rows;
}

int Matrix::getCols()
{
    return cols;
}

void Matrix::print()
{
    for (int i = 0; i < m_data.size(); i++)
    {
        std::cout << m_data[i] << " ";
        if ((i + 1) % cols == 0)
        {
            std::cout << std::endl;
        }
    }
}
    double &Matrix::at(int r, int c)
    {
        if (r > (rows - 1) || c > (cols - 1))
        {
            std::cout << "(" << r << "," << c << ") is not a valid position !" << std::endl;
            return m_data[0];
        }
        else
        {
            int n = (r * cols) + c;
            return m_data[n];
        }
    }

    Matrix Matrix::add(Matrix matrix)
    {
        Matrix newMatrix(rows, cols);
        if (rows == matrix.getRows() && cols == matrix.getCols())
        {
            for (int i = 0; i < m_data.size(); i++)
            {
                newMatrix.m_data[i] = m_data[i] + matrix.m_data[i];
            }
        }
        else
        {
            std::cout << "Matrix is not equal size!" << std::endl;
        }
        return newMatrix;
    }
    Matrix Matrix::multiply(Matrix matrix)
    {
        Matrix newMatrix(rows, matrix.getCols());
        double val = 0.0;
        if (cols != matrix.getRows())
        {
            std::cout << "The matrix' does not have a product" << std::endl;
            return newMatrix;
        }
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < matrix.getCols(); j++)
            {
                for (int n = 0; n < cols; n++)
                {
                    val += (at(i, n) * matrix.at(n, j));
                }
                newMatrix.at(i, j) = val;
                val = 0;
            }
        }
        return newMatrix;
    }

    void Matrix::transpose()
    {
        Matrix newMatrix(cols, rows);
        for (int r = 0; r < cols; r++)
        {
            for (int c = 0; c < rows; c++)
            {
                newMatrix.at(r, c) = at(c, r);
            }
        }
        *this = newMatrix;
    }

    double &Matrix::operator()(int r, int c)
    {
        return at(r, c);
    }

    Matrix Matrix::operator+(Matrix m)
    {
        return add(m);
    }

    Matrix Matrix::operator*(Matrix m)
    {
        return multiply(m);
    }

    Matrix Matrix::operator*(double v)
    {
        Matrix newMatrix(rows, cols);
        for (int i = 0; i < m_data.size(); i++)
        {
            newMatrix.m_data[i] = m_data[i] * v;
        }
        return newMatrix;
        return newMatrix;
}