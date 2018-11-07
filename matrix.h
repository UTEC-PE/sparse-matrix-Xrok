#ifndef MATRIX_H
#define MATRIX_H

#include "node.h"

using namespace std;

template <typename T>
class Matrix { 
    private:
        Node<T>* hRows;
        Node<T>* hColumns;
        int columns;
        int rows;

    public:
        Matrix();
        Matrix(int sizeX, int sizeY){
            int zero =0;
            columns = sizeX;
            rows = sizeY;
            hRows = new Node<T>() ;

        };

        void set(int x, int y, T data);
        T operator()(int x, int y);
        Matrix<T> operator*(Matrix<T> other);
        Matrix<T> operator*(T scalar);
        Matrix<T> operator+(Matrix<T> other);
        Matrix<T> operator-(Matrix<T> other);
        Matrix<T> transposed();
        Matrix<T> operator=(Matrix<T> other);

        ~Matrix();
};

#endif