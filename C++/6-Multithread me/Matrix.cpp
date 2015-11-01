#include <cmath>
#include <iostream>
#include "Matrix.h"

template<typename T>
Matrix<T>::Matrix(int row, int col) {
    matrix = new T *[row];
    for (int i = 0; i < row; i++) {
        matrix[i] = new T[col];
        for (int j = 0; j < col; j++) {
            matrix[i][j] = j % 2 ? i * col + j : -i * col + j;
        }
    }

    size_row = row;
    size_col = col;
}

template<typename T>
T Matrix<T>::cellsSum() {
    T sum{0};
    for (int row=0; row<getRow(); row++) {
        for (int col=0; col<getCol(); col++) {
            sum += matrix[row][col];
        }
    }
    return sum;
}

template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    matrix[row][col] = value;
}

template<typename T>
T Matrix<T>::get(int row, int col) const {
    return matrix[row][col];
}


template<typename T>
void Matrix<T>::print() {
    for (int i = 0; i < size_row; i++) {
        for (int j = 0; j < size_col; j++) {
            std::cout << matrix[i][j] << ",";
        }
        std::cout << std::endl;
    }
}


template<typename T>
unsigned int Matrix<T>::getRow() const {
    return size_row;
}

template<typename T>
unsigned int Matrix<T>::getCol() const {
    return size_col;
}

template
class Matrix<int>;

template
class Matrix<long>;

template
class Matrix<unsigned long>;

template
class Matrix<unsigned long long>;

template
class Matrix<double>;

template
class Matrix<float>;
