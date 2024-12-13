#include <iostream>

class Fixed {
    private:
        int nb;
        static const unsigned char fractional; 
    public:
        Fixed();
        Fixed(const Fixed &source);
        Fixed &operator=(const Fixed &source);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
};