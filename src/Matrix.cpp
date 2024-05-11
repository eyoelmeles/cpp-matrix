#include "Matrix.h"
#include <iostream>

Matrix::Matrix(int rows, int cols, double initialValue) {
    data.resize(rows, std::vector<double>(cols, initialValue));
}

void Matrix::display() const {
    for (int i = 0; i < getRows(); i++) {
        for (int j = 0; j < getCols(); j++) {
            std::cout << at(i, j) << " ";
        }
        std::cout << std::endl;
    }
}

int Matrix::getRows() const {
    return data.size();
}

int Matrix::getCols() const {
    return data.empty() ? 0 : data[0].size();
}

double Matrix::at(int row, int col) const {
    if (row >= getRows() || col >= getCols() || row < 0 || col < 0) {
        throw std::out_of_range("Matrix indices out of range");
    }
    return data[row][col];
}

void Matrix::set(int row, int col, double value) {
    if (row >= getRows() || col >= getCols() || row < 0 || col < 0) {
        throw std::out_of_range("Matrix indices out of range");
    }
    data[row][col] = value;
}

Matrix Matrix::operator+(const Matrix& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        throw std::invalid_argument("Matrix dimenstions must match for addition");
    }
    Matrix result(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            result.set(i, j, this->at(i, j) + other.at(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        throw std::invalid_argument("Matrix dimenstions must match for addition");
    }
    Matrix result(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            result.set(i, j, this->at(i, j) - other.at(i, j));
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (this->getRows() != other.getRows() || this->getCols() != other.getCols()) {
        throw std::invalid_argument("Matrix dimenstions must match for addition");
    }
    Matrix result(this->getRows(), this->getCols());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            result.set(i, j, this->at(i, j) * other.at(i, j));
        }
    }
    return result;
}

Matrix Matrix::transpose() const {
    Matrix transposed(this->getCols(), this->getRows());
    for (int i = 0; i < this->getRows(); i++) {
        for (int j = 0; j < this->getCols(); j++) {
            transposed.set(j, i, this->at(i, j));
        }
    }
    return transposed;
}
