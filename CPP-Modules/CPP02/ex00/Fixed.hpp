#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {
    private:
        static const int _fractionalBits = 8;
        int              _fixedPointValue;
    public:
        Fixed(void);
        Fixed(Fixed const &src);
        ~Fixed(void);
        Fixed &operator=(Fixed const &rhs);
        int getRawBits(void) const;
        void setRawBits(int const raw);
};

#endif