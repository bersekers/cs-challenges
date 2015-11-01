#ifndef THREADS_MATRIX_H
#define THREADS_MATRIX_H

#include <exception>

template <typename T>
class Matrix {
public:
    Matrix(int x, int y);
    T get(int row, int col) const;
    void set(int row, int col, T value);
    void print();
    T cellsSum();
    unsigned int getRow() const;
    unsigned int getCol() const;

protected:
    T** matrix;
    int size_row;
    int size_col;
};


#endif //THREADS_MATRIX_H
