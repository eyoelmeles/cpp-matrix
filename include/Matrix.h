#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <stdexcept>

class Matrix {
    private:
        std::vector<std::vector<double>> data;
    public:
        Matrix(int rows, int cols, double initialValue = 0.0);

        void display() const;
        int getRows() const;
        int getCols() const;
        double at(int row, int col) const;

        void set(int row, int col, double value);

        Matrix operator+(const Matrix& other) const;
        Matrix operator-(const Matrix& other) const;
        Matrix operator*(const Matrix& other) const;

        Matrix transpose() const;
};

#endif