#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template<typename T>
class Array {
    private:
        T* data;
        unsigned int _size;
    public:
        Array();
        Array(unsigned int n);
        Array(const Array &copy);
        Array &operator=(const Array &copy);
        ~Array();

        T& operator[](unsigned int i);
        const T& operator[](unsigned int i) const;

        unsigned int size() const;
};

#include "Array.tpp"


#endif