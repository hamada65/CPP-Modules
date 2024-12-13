#include "Fixed.hpp"

const unsigned char Fixed::fractional = 8;

Fixed::Fixed() : nb(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int &new_nb) : nb(new_nb << fractional) {
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float &new_nb) {
    // fixed_point_value = round(float_value × 2 fractional)
    nb = roundf(new_nb * (1 << fractional));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source) {
    std::cout << "Copy constructor called" << std::endl;
    *this = source;
}

Fixed &Fixed::operator=(const Fixed &source) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this == &source)
        return *this;
    
    nb = source.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

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

std::ostream &operator<<(std::ostream &oStream, const Fixed &value) {
    oStream << value.toFloat();
    return oStream;
}