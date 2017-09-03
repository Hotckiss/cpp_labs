#ifndef _MY_VECTOR_H_INCLUDED
#define _MY_VECTOR_H_INCLUDED

#include <cstddef>
#include <iostream>
template <class T>
class my_vector {
public:
    my_vector() {
        size_ = 0;
        capacity_ = 2;
        array_ = (T*)(new char[sizeof(T) * capacity_]);
    }

    my_vector(size_t n) {
        size_ = n;
        capacity_ = get(n);
        array_ = (T*)(new char[sizeof(T) * capacity_]);
        for (size_t i = 0; i < size_; ++i)
            new (&array_[i]) T();
    }
    my_vector(const my_vector<T>& other) {
        array_ = (T*)(new char[sizeof(T) * other.capacity()]);
        size_ = other.size();
        capacity_ = other.capacity();
        for (size_t i = 0; i < other.size_; ++i)
            new (&array_[i]) T(other.array_[i]);
    }
    my_vector<T>& operator=(const my_vector<T>& other) {
        for (size_t i = 0; i < size_; ++i)
            array_[i].~T();
        delete[](char*)array_;
        array_ = (T*)(new char[sizeof(T) * other.capacity()]);
        size_ = other.size();
        capacity_ = other.capacity();
        for (size_t i = 0; i < other.size_; ++i)
            new (&array_[i]) T(other.array_[i]);
        return *this;
    }

    ~my_vector() {
        for (size_t i = 0; i < size_; ++i)
            array_[i].~T();
        delete[](char*)array_;
    }

    size_t size() const {
        return size_;
    }

    size_t capacity() const {
        return capacity_;
    }

    bool empty() const {
        return size_ ? false : true;
    }

    void resize(size_t n) {
        reserve(n);
        if (size_ < n) {
            for (size_t i = size_; i < n; ++i)
                new (&array_[i]) T();
            size_ = n;
        }
        else if (size_ > n) {
            size_t iter = size_ - n;
            for (size_t i = 0; i < iter; ++i)
                pop_back();
        }
    }

    void reserve(size_t n) {
        if (capacity_ < n) {
            capacity_ = get(n);
            T* buffer = (T*)(new char[sizeof(T) * capacity_]);
            for (size_t i = 0; i < size_; ++i)
                new (&buffer[i]) T(array_[i]);
            for (size_t i = 0; i < size_; ++i)
                array_[i].~T();
            delete[](char*)array_;
            array_ = buffer;
        }
    }

    T & operator[](size_t index) {
        return array_[index];
    }

    T & operator[](size_t index) const {
        return array_[index];
    }
    void push_back(const T & t) {
        if (size_ == capacity_)
            reserve(2 * capacity_);
        new (&array_[size_]) T(t);
        size_++;
    }

    void pop_back() {
        array_[size_ - 1].~T();
        size_--;
    }

    void clear() {
        for (size_t i = 0; i < size_; ++i)
            array_[i].~T();
        size_ = 0;
    }

    template<class TT>
    friend std::ostream& operator<<(std::ostream& fout, const my_vector<TT>& v);

private:
    size_t get(size_t n) const {
        size_t ans = 1;
        while (ans < n) ans *= 2;
        return ans;
    }
    size_t capacity_;
    size_t size_;
    T* array_;
};

#endif