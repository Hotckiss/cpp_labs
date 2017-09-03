#ifndef _MATRIX_H_INCLUDED
#define _MATRIX_H_INCLUDED

#include <cstdio>
#include <cstddef>
#include <iostream>
#include <string>
#include <fstream>

class Matrix {
public:
    Matrix();
    Matrix(std::size_t r, std::size_t c);
    Matrix(const Matrix &m);
    ~Matrix();
    std::size_t get_rows() const;
    std::size_t get_cols() const;
    void set(const std::size_t i, const std::size_t j, const int val);
    int get(const std::size_t i, const std::size_t j) const;
    void print(std::ostream & os) const;
    void swap(Matrix & m);
    Matrix& operator=(const Matrix& m);

    Matrix& operator+=(const Matrix& m);
    Matrix& operator*=(const Matrix& m);
private:
    std::size_t _rows;
    std::size_t _cols;
    int **_data;
};

class MatrixException {
private:
    std::string _message;
public:
    MatrixException(const std::string &_message) : _message(_message) {}
    std::string GetErrorMessage() const { 
        return _message; 
    }
};

#endif