#include <iostream>
#include "Fixed.hpp"

int main( void ) {

    Fixed a;
    Fixed b( a );
    Fixed c;
    
    c = b;

    a.setRawBits(42);
    b.setRawBits(21);
    c.setRawBits(84);

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
