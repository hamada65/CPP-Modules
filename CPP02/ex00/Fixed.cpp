#include "Fixed.hpp"

const unsigned char Fixed::fractional = 8;

Fixed::Fixed() : nb(0) {
    std::cout << "Default constructor called" << std::endl;
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
    std::cout << "getRawBits member function called" << std::endl;
    return nb;
}

void    Fixed::setRawBits( int const raw ) {
    nb = raw;
}