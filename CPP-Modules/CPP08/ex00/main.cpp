#include "easyfind.hpp"

int main() {
    try {
        // Test avec tableau
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        
        std::vector<int>::iterator it = easyfind(v, 3);
        std::cout << "Trouvé dans vecteur: " << *it << std::endl;
        
        // Test avec liste chainee
        std::list<int> l;
        l.push_back(10);
        l.push_back(20);
        l.push_back(30);
        
        std::list<int>::iterator it2 = easyfind(l, 20);
        std::cout << "Trouvé dans liste: " << *it2 << std::endl;
        
        // Fail
        easyfind(v, 99);  // Va lancer une exception
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}