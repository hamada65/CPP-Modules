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
        ~Fixed();

        Fixed &operator=(const Fixed &source);

        bool operator>(const Fixed &source) const;
        bool operator<(const Fixed &source) const;
        bool operator>=(const Fixed &source) const;
        bool operator<=(const Fixed &source) const;
        bool operator==(const Fixed &source) const;
        bool operator!=(const Fixed &source) const;

        float operator+(const Fixed &source) const;
        float operator-(const Fixed &source) const;
        float operator*(const Fixed &source) const;
        float operator/(const Fixed &source) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        int     getRawBits( void ) const;
        void    setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;
        
        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &oStream, const Fixed &value);