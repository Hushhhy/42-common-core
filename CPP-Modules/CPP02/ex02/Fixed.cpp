#include "Fixed.hpp"

Fixed::Fixed(void) {
    this->_fixedPointValue = 0;
}

Fixed::Fixed(const int value) {
    this->_fixedPointValue = value << this->_fractionalBits;
}

Fixed::~Fixed(void) {
}

Fixed::Fixed(const float value) {
     this->_fixedPointValue = roundf(value * (1 << this->_fractionalBits));
}

bool Fixed::operator>(Fixed const &rhs) const {
    return this->_fixedPointValue > rhs._fixedPointValue;
}

bool Fixed::operator<(Fixed const &rhs) const {
    return this->_fixedPointValue < rhs._fixedPointValue;
}

bool Fixed::operator>=(Fixed const &rhs) const {
    return this->_fixedPointValue >= rhs._fixedPointValue;
}

bool Fixed::operator<=(Fixed const &rhs) const {
    return this->_fixedPointValue <= rhs._fixedPointValue;
}

bool Fixed::operator==(Fixed const &rhs) const {
    return this->_fixedPointValue == rhs._fixedPointValue;
}

bool Fixed::operator!=(Fixed const &rhs) const {
    return this->_fixedPointValue != rhs._fixedPointValue;
}

Fixed Fixed::operator+(Fixed const &rhs) const {
    Fixed result;

    result._fixedPointValue = this->_fixedPointValue + rhs._fixedPointValue;
    return result;
}

Fixed Fixed::operator-(Fixed const &rhs) const {
    Fixed result;

    result._fixedPointValue = this->_fixedPointValue - rhs._fixedPointValue;
    return result;
}

Fixed Fixed::operator*(Fixed const &rhs) const {
    Fixed result;

    result._fixedPointValue = (this->_fixedPointValue * rhs._fixedPointValue) >> this->_fractionalBits;
    return result;
}

Fixed Fixed::operator/(Fixed const &rhs) const {
    Fixed result;

    result._fixedPointValue = (this->_fixedPointValue << this->_fractionalBits) / rhs._fixedPointValue;
    return result;
}

Fixed &Fixed::operator++(void) {
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);

    operator++();
    return tmp;
}

Fixed &Fixed::operator--(void) {
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);

    operator--();
    return tmp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return a < b ? a : b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {
    return a < b ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return a > b ? a : b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {
    return a > b ? a : b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed) {
    out << fixed.toFloat(); // Convertit l'objet Fixed en float pour l'affichage
    return out;
}

float Fixed::toFloat(void) const {
    return (float)this->_fixedPointValue / (1 << this->_fractionalBits);
}
