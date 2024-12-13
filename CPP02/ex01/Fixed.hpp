#include <iostream>
#include <cmath>

class Fixed {
    private:
        int nb;
        static const unsigned char fractional; 
    public:
        Fixed();
        Fixed(const Fixed &source);
        Fixed(const int &new_nb);
        Fixed(const float &new_nb);
        Fixed &operator=(const Fixed &source);
        ~Fixed();
        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &oStream, const Fixed &value);