#include "../include/my_vector.h"
#include <cassert>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cstdio>

MyVector::MyVector() {
    _data = (MySuperPuperVectorType *)malloc(sizeof(MySuperPuperVectorType) * 2);
    _sz = 0;
    _cp = 2;
}
MyVector::MyVector(std::size_t init_capacity) {
    _cp = init_capacity;
    _sz = 0;
    _data = (MySuperPuperVectorType *)malloc(sizeof(MySuperPuperVectorType) * init_capacity);
}
MyVector::~MyVector() {
    free(_data);
}
void MyVector::set(std::size_t index, MySuperPuperVectorType value) {
    assert(0 <= index && index < _sz);
    _data[index] = value;
}
MySuperPuperVectorType MyVector::get(std::size_t index) {
    assert(0 <= index && index < _sz);
    return _data[index];
}
std::size_t MyVector::size() {
    return _sz;
}
std::size_t MyVector::capacity() {
    return _cp;
}
void MyVector::reserve(std::size_t new_capacity) {
    if (_cp < new_capacity) {
        _data = (MySuperPuperVectorType *)realloc(_data, new_capacity * sizeof(MySuperPuperVectorType));
        _cp = new_capacity;
    }
}
void MyVector::resize(std::size_t new_size) {
    if (_cp < new_size) {
        while (_cp < new_size)
            _cp *= 2;
        _data = (MySuperPuperVectorType *)realloc(_data, _cp * sizeof(MySuperPuperVectorType));
    }
    for (size_t i = _sz; i < new_size; i++)
        _data[i] = 0;
    _sz = new_size;
}
void MyVector::push_back(MySuperPuperVectorType value) {
    if (_sz == _cp) {
        _data = (MySuperPuperVectorType *)realloc(_data, 2 * _cp * sizeof(MySuperPuperVectorType));
        _cp *= 2;
    }
    _data[_sz] = value;
    _sz++;
}
void MyVector::insert(std::size_t index, MySuperPuperVectorType value) {
    assert(0 <= index && index <= _sz);
    if (_sz == _cp) {
        _data = (MySuperPuperVectorType *)realloc(_data, 2 * _cp * sizeof(MySuperPuperVectorType));
        _cp *= 2;
    }
    _sz++;
    for (size_t i = _sz - 1; i > index; i--)
        _data[i] = _data[i - 1];
    _data[index] = value;
}
void MyVector::erase(std::size_t index) {
    assert(0 <= index && index < _sz);
    for (size_t i = index; i < _sz - 1; i++)
        _data[i] = _data[i + 1];
    _sz--;
}
