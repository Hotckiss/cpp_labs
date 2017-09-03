#include "matrix.h"
#include <algorithm>

Matrix::Matrix() {
    _rows = 0;
    _cols = 0;
}

Matrix::Matrix(std::size_t r, std::size_t c) {
    _rows = r;
    _cols = c;
    if(r && c) {
        int *buffer = new int[r * c]();
        _data = new int*[r];
        for (std::size_t i = 0; i < r; i++)
            _data[i] = buffer + i * c;
    }
}

Matrix::Matrix(const Matrix &m) {
    _rows = m._rows;
    _cols = m._cols;
    if(_cols && _rows) {
        int *buffer = new int[_rows * _cols]();
        _data = new int*[_rows];
        for (std::size_t i = 0; i < _rows; i++)
            _data[i] = buffer + i * _cols;
        for (std::size_t i = 0; i < _rows; i++)
            for (std::size_t j = 0; j < _cols; j++)
                _data[i][j] = m._data[i][j];
    }
}

Matrix::~Matrix() {
    if (_cols > 0 && _rows > 0) {
        delete[] * _data;
        delete[] _data;
    }
}

std::size_t Matrix::get_rows() const {
    return _rows;
}

std::size_t Matrix::get_cols() const {
    return _cols;
}

Matrix& Matrix::operator=(const Matrix& m) {
    if (this != &m)
        Matrix(m).swap(*this);
    return *this;
}

void Matrix::swap(Matrix & m) {
    std::swap(this->_data, m._data);
    std::swap(this->_rows, m._rows);
    std::swap(this->_cols, m._cols);
}

void Matrix::set(std::size_t i, std::size_t j, int val) {
    if (i >= _rows || j >= _cols) {
        std::string ErrorMessage("ACCESS: bad index.\n");
        throw MatrixException(ErrorMessage);
    }
    _data[i][j] = val;
}

int Matrix::get(std::size_t i, std::size_t j) const {
    if (i >= _rows || j >= _cols) {
        std::string ErrorMessage("ACCESS: bad index.\n");
        throw MatrixException(ErrorMessage);
    }

    return _data[i][j];
}

void Matrix::print(std::ostream & os) const {
    for (std::size_t i = 0; i < _rows; i++) {
        for (std::size_t j = 0; j < _cols; j++)
            os << this->_data[i][j] << " ";
        os << "\n";
    }
}

Matrix& Matrix::operator+=(const Matrix& m) {
    if (_rows != m.get_rows() || _cols != m.get_cols()) {
        std::string ErrorMessage("ADD: dimensions do not match.\n");
        throw MatrixException(ErrorMessage);
    }
    for (std::size_t i = 0; i < _rows; i++)
        for (std::size_t j = 0; j < _cols; j++)
            this->_data[i][j] += m._data[i][j];
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& m) {
    if (_cols != m.get_rows()) {
        std::string ErrorMessage("MUL: #arg1.columns != #arg2.rows.\n");
        throw MatrixException(ErrorMessage);
    }

    Matrix ans(this->_rows, m._cols);
    for (std::size_t i = 0; i < ans._rows; i++)
        for (std::size_t j = 0; j < ans._cols; j++)
            for (std::size_t k = 0; k < this->_cols; k++)
                ans._data[i][j] += this->_data[i][k] * m._data[k][j];
    ans.swap(*this);
    return *this;
}
