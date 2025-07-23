#include "iter.hpp"


template<typename T>
void print(const T& elem) {
    std::cout << elem << std::endl;
}

template<typename T>
void increment(T& elem) {
    ++elem;
}

int main() {
    int intArray[] = {1, 2, 3, 4, 5};
    std::string strArray[] = {"alpha", "beta", "gamma"};

    std::cout << "== Integer array ==" << std::endl;
    iter(intArray, 5, print<int>);
    
    std::cout << "== After increment ==" << std::endl;
    iter(intArray, 5, increment<int>);
    iter(intArray, 5, print<int>);

    std::cout << "== String array ==" << std::endl;
    iter(strArray, 3, print<std::string>);

    return 0;
}