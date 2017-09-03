#ifndef MY_ARRAY_H_
#define MY_ARRAY_H_

#include <iostream>
#include <cstdlib>
#include <stdint.h>

template<typename T, std::size_t N>
class my_array {
public:
    const T & at(std::size_t index) const {
        check_index(index);
        return (*this)[index];
    }

    T & at(std::size_t index) {
        check_index(index);
        return (*this)[index];
    }

    const T & operator[](std::size_t index) const {
        return array_[index];
    }

    T & operator[](std::size_t index) {
        return array_[index];
    }

    bool empty() const {
        return (N == 0);
    }

    std::size_t size() const {
        return N;
    }

    void fill(const T & val) {
        for (std::size_t i = 0; i < N; i++)
            array_[i] = val;
    }
private:
    void check_index(std::size_t index) const {
        if ((index < 0) || (index >= N)) {
            std::cerr << "Incorrect index." << std::endl;
            exit(1);
        }
    }
    T array_[N];
};

template<std::size_t N>
class my_array<bool, N> {
private:
    class Proxy {
    public:
        Proxy(uint8_t *byte, std::size_t pos) : byte(byte), pos(pos) {}
        operator bool() const {
            return ((*byte) >> pos) & 1;
        }
        void operator=(bool new_val) {
            if (new_val)
                (*byte) |= (1 << pos);
            else
                (*byte) &= (~(1 << pos));
        }
        Proxy& operator=(const Proxy &proxy) {
            *this = (bool)proxy;
            return *this;
        }
        uint8_t *byte;
        std::size_t pos;
    };
    void check_index(std::size_t index) const {
        if ((index < 0) || (index >= N)) {
            std::cerr << "Incorrect index." << std::endl;
            exit(1);
        }
    }
    const static std::size_t size_ = (N + 7) / 8;
    uint8_t array_[size_];
public:
    my_array() {
        for (std::size_t i = 0; i < size_; i++)
            array_[i] = 0;
    }
    bool at(std::size_t index) const {
        check_index(index);
        return (*this)[index];
    }

    Proxy at(std::size_t index) {
        check_index(index);
        return (*this)[index];
    }

    bool operator[](std::size_t index) const {
        return (bool)Proxy((uint8_t *)&array_[index / 8], index % 8);
    }

    Proxy operator[](std::size_t index) {
        return Proxy((uint8_t *)&array_[index / 8], index % 8);
    }

    bool empty() const {
        return (N == 0);
    };
    std::size_t size() const {
        return N;
    }

    void fill(const bool val) {
        uint8_t fill_val = val ? 0xFF : 0;
        for (std::size_t i = 0; i < size_; i++)
            array_[i] = fill_val;
    }
};

#endif