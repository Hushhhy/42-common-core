#include "Base.hpp"

Base::~Base() {}

Base * generate(void) {
    int r = std::rand() % 3;

    switch (r) {
        case 0:
            std::cout << "Generated: A" << std::endl;
            return new A;
        case 1:
            std::cout << "Generated: B" << std::endl;
            return new B;
        case 2:
            std::cout << "Generated: C" << std::endl;
            return new C;
    }
    return NULL;
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown type" << std::endl;
}

void identify(Base& p) {
    try {
        dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {}

    try {
        dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {}

    std::cout << "Unknown type" << std::endl;
}