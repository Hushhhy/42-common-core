#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> empty;
        std::cout << "Empty array size: " << empty.size() << std::endl;

        // Test parameterized constructor
        Array<int> intArray(5);
        std::cout << "Int array size: " << intArray.size() << std::endl;
        
        // Fill array
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            intArray[i] = i * 2;
        }
        
        // Print array
        std::cout << "Int array contents: ";
        for (unsigned int i = 0; i < intArray.size(); ++i) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copy(intArray);
        std::cout << "Copy array size: " << copy.size() << std::endl;
        
        // Modify original to test deep copy
        intArray[0] = 999;
        std::cout << "Original[0]: " << intArray[0] << ", Copy[0]: " << copy[0] << std::endl;

        // Test assignment operator
        Array<int> assigned;
        assigned = copy;
        std::cout << "Assigned array size: " << assigned.size() << std::endl;

        // Test out of bounds exception
        try {
            intArray[10] = 42;
        } catch (const std::exception& e) {
            std::cout << "Exception caught: " << e.what() << std::endl;
        }

        // Test with strings
        Array<std::string> strArray(3);
        strArray[0] = "Hello";
        strArray[1] = "World";
        strArray[2] = "!";
        
        std::cout << "String array: ";
        for (unsigned int i = 0; i < strArray.size(); ++i) {
            std::cout << strArray[i] << " ";
        }
        std::cout << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}