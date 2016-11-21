#include "../include/matrix.h"
#include <algorithm>
Matrix::Matrix(std::size_t r, std::size_t c) {
    int *buffer = new int [r * c]();
    _data = new int*[r];
    for (std::size_t i = 0; i < r; i++)
        _data[i] = buffer + i * c;
    _rows = r;
    _cols = c;
}
Matrix::Matrix(const Matrix &m) {
    _rows = m._rows;
    _cols = m._cols;
    int *buffer = new int[_rows * _cols]();
    _data = new int*[_rows];
    for (std::size_t  i = 0; i < _rows; i++)
        _data[i] = buffer + i * _cols;
    for (std::size_t i = 0; i < _rows; i++)
        for (std::size_t j = 0; j < _cols; j++)
            _data[i][j] = m._data[i][j];
}
Matrix::~Matrix() {
    delete[] * _data;
    delete[] _data;
}
std::size_t Matrix::get_rows() const {
    return _rows; 
}
std::size_t Matrix::get_cols() const {
    return _cols; 
}
Matrix& Matrix::operator=(const Matrix& m) {
    if(this != &m) 
        Matrix(m).swap(*this);
    return *this;
}
void Matrix::swap(Matrix & m) {
    std::swap(this->_data, m._data);
    std::swap(this->_rows, m._rows);
    std::swap(this->_cols, m._cols);
}
void Matrix::set(std::size_t i, std::size_t j, int val) {
    _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
    return _data[i][j];
}

void Matrix::print(FILE* f) const {
    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++)
            fprintf(f, "%i ", this->_data[i][j]);
        fprintf(f, "\n");
    }
}

bool Matrix::operator==(const Matrix& m) const {
    if (this->_rows != m._rows || this->_cols != m._cols)
        return false;
    for (std::size_t i = 0; i < _rows; i++)
        for (std::size_t j = 0; j < _cols; j++)
            if (this->_data[i][j] != m._data[i][j])
                return false;
    return true;
}

bool Matrix::operator!=(const Matrix& m) const {
    if(*this == m)
        return false;
    return true;
}

Matrix& Matrix::operator+=(const Matrix& m) {
    for (std::size_t i = 0; i < _rows; i++)
        for (std::size_t j = 0; j < _cols; j++)
            this->_data[i][j] += m._data[i][j];
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& m) {
    for (std::size_t i = 0; i < _rows; i++)
        for (std::size_t j = 0; j < _cols; j++)
            this->_data[i][j] -= m._data[i][j];
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
    Matrix ans(this->_rows, m._cols);
    for (std::size_t i = 0; i < ans._rows; i++)
        for (std::size_t j = 0; j < ans._cols; j++)
            for (std::size_t k = 0; k < this->_cols; k++)
                ans._data[i][j] += this->_data[i][k] * m._data[k][j];
    ans.swap(*this);
    return *this;
}

Matrix Matrix::operator+(const Matrix& m) const {
    Matrix tmp(*this);
    return tmp += m;
}

Matrix Matrix::operator-(const Matrix& m) const {
    Matrix tmp(*this);
    return tmp -= m;
}

Matrix Matrix::operator*(const Matrix& m) const {
    Matrix tmp(*this);
    return tmp *= m;
}
