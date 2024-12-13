#include "Fixed.hpp"

const unsigned char Fixed::fractional = 8;

Fixed::Fixed() : nb(0) {}

Fixed::Fixed(const int &new_nb) : nb(new_nb << fractional) {}

Fixed::Fixed(const float &new_nb) {
    // fixed_point_value = round(float_value × 2 fractional)
    nb = roundf(new_nb * (1 << fractional));
}

Fixed::Fixed(const Fixed &source) {
    *this = source;
}

Fixed::~Fixed() {}

int     Fixed::getRawBits( void ) const {
    return nb;
}

void    Fixed::setRawBits( int const raw ) {
    nb = raw;
}

float Fixed::toFloat( void ) const {
    return (float)nb / (1 << fractional);
}

int Fixed::toInt( void ) const {
    return nb >> fractional;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    return (a.toFloat() < b.toFloat()) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
    return (a.toFloat() < b.toFloat()) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    return (a.toFloat() > b.toFloat()) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
    return (a.toFloat() > b.toFloat()) ? a : b;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &source) {
    if (this == &source)
        return *this;
    
    nb = source.getRawBits();
    return *this;
}

std::ostream &operator<<(std::ostream &oStream, const Fixed &value) {
    oStream << value.toFloat();
    return oStream;
}

bool Fixed::operator>(const Fixed &source) const {
    return nb > source.getRawBits();
}

bool Fixed::operator<(const Fixed &source) const {
    return nb < source.getRawBits();
}

bool Fixed::operator>=(const Fixed &source) const {
    return nb >= source.getRawBits();
}

bool Fixed::operator<=(const Fixed &source) const {
    return nb <= source.getRawBits();
}

bool Fixed::operator==(const Fixed &source) const {
    return nb == source.getRawBits();
}

bool Fixed::operator!=(const Fixed &source) const {
    return nb != source.getRawBits();
}

float Fixed::operator+(const Fixed &source) const {
    return toFloat() + source.toFloat();
}

float Fixed::operator-(const Fixed &source) const {
    return toFloat() - source.toFloat();
}

float Fixed::operator*(const Fixed &source) const {
    return toFloat() * source.toFloat();
}

float Fixed::operator/(const Fixed &source) const {
    return toFloat() / source.toFloat();
}

Fixed &Fixed::operator++() {
    nb++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    nb--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}
