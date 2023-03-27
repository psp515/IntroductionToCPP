#include <iostream>
#include <string>
#include <stdexcept> // std::out_of_range()
#include <iomanip>   // std::setw()

using namespace std;

#include "matrix.h"

TwoDimensionMatrix::TwoDimensionMatrix() {

    for(size_t i = 0; i < size(); i++)
        for(size_t j = 0; j < size(); j++)
            matrix_[i][j] = 0;
}

TwoDimensionMatrix::TwoDimensionMatrix(const TwoDimensionMatrix &matrix) {
    for(size_t i = 0; i < size(); i++)
        for(size_t j = 0; j < size(); j++)
            matrix_[i][j] = matrix.get(i, j);
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement (&matrix)[2][2]) {

    for(size_t i = 0; i < size(); i++)
        for(size_t j = 0; j < size(); j++)
            matrix_[i][j] = matrix[i][j];
}

MatrixElement TwoDimensionMatrix::get(size_t i, size_t j) const{
    return matrix_[i][j];
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &other) {

    for(size_t i = 0; i < size_; i++)
        for(size_t j = 0; j < size_;j++)
            this->matrix_[i][j] = other.matrix_[i][j];

    return *this;
}

ostream &operator<<(ostream &os, const TwoDimensionMatrix &matrix) {

    for(size_t i = 0; i < matrix.size(); i++)
    {
        for(size_t j = 0; j < matrix.size(); j++)
            os << matrix.matrix_[i][j];

        os << "\n";
    }

    return os;
}

istream &operator>>(istream &is, TwoDimensionMatrix &matrix) {

    for(size_t i = 0; i < matrix.size(); i++)
        for(size_t j = 0; j < matrix.size(); j++)
            is >> matrix.matrix_[i][j];

    return is;
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {

    for(size_t i = 0; i < size(); i++)
        for(size_t j = 0; j < size(); j++)
            matrix_[i][j] *= number;

    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix &matrix) const {

    MatrixElement resultMatrix[2][2];

    for(size_t i = 0; i < matrix.size(); i++)
        for(size_t j = 0; j < matrix.size(); j++)
            resultMatrix[i][j] = this->get(i,j) && matrix.get(i,j);

    TwoDimensionMatrix result(resultMatrix);

    return result;
}


TwoDimensionMatrix operator+(const TwoDimensionMatrix& matrix1, const TwoDimensionMatrix& matrix2)
{
    MatrixElement resultMatrix[2][2];

    for(size_t i = 0; i < matrix1.size(); i++)
        for(size_t j = 0; j < matrix1.size(); j++)
            resultMatrix[i][j] = matrix1.get(i,j) + matrix2.get(i,j);

    TwoDimensionMatrix result(resultMatrix);

    return result;
}

