#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array &copy) : data(new T[copy._size]), _size(copy._size) {
    for (unsigned int i = 0; i < _size; ++i) {
        data[i] = copy.data[i];
    }
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy) {
    if (this != &copy) {
        delete[] data;
        _size = copy._size;
        data = new T[_size];
        for (unsigned int i = 0; i < _size; ++i) {
            data[i] = copy.data[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](unsigned int i) {
    if (i >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[i];
}

template <typename T>
const T& Array<T>::operator[](unsigned int i) const {
    if (i >= _size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[i];
}

template <typename T>
unsigned int Array<T>::size() const {
    return _size;
}


#endif