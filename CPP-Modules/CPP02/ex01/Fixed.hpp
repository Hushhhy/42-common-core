#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class  Fixed {
    public :
        Fixed(const int value);
        Fixed(const float value);
        Fixed(void);
        ~Fixed(void);
        float toFloat(void) const;
        int   toInt(void) const;
    private :
        int _fixedPointValue;
        static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif