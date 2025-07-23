#include "Serializer.hpp"
#include "Data.hpp"

int main() {
    Data* ptr = new Data;
    ptr->str = "Hello";
    ptr->i = 42;
    ptr->f = 3.14f;
    ptr->d = 2.718281828;

    std::cout << "=== ptr Data ===" << std::endl;
    std::cout << "Address: " << ptr << std::endl;
    std::cout << "str: " << ptr->str << std::endl;
    std::cout << "i: " << ptr->i << std::endl;
    std::cout << "f: " << ptr->f << std::endl;
    std::cout << "d: " << ptr->d << std::endl;

    uintptr_t serialized = Serializer::serialize(ptr);
    std::cout << "\n=== Serialization ===" << std::endl;
    std::cout << "Serialized value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "\n=== Deserialized Data ===" << std::endl;
    std::cout << "Address: " << deserialized << std::endl;
    std::cout << "str: " << deserialized->str << std::endl;
    std::cout << "i: " << deserialized->i << std::endl;
    std::cout << "f: " << deserialized->f << std::endl;
    std::cout << "d: " << deserialized->d << std::endl;

    std::cout << "\n=== Verification ===" << std::endl;
    if (ptr == deserialized)
        std::cout << "Success: Pointers are identical!" << std::endl;
    else {
        std::cout << "Error: Pointers are different!" << std::endl;
    }

    delete ptr;
    return 0;
}