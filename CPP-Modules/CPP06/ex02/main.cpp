#include "Base.hpp"

int main() {
    std::srand(std::time(NULL));

    // Test avec 5 objets générés aléatoirement
    for (int i = 0; i < 5; i++) {
        std::cout << "=== Test " << (i + 1) << " ===" << std::endl;
        
        Base* obj = generate();
        
        std::cout << "Identify by pointer: ";
        identify(obj);
        
        std::cout << "Identify by reference: ";
        identify(*obj);
        
        delete obj;
    }
    return 0;
}