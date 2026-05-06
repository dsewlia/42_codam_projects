#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class   Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed(const int num);
        Fixed(const float num);
        Fixed   &operator=(const Fixed &rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat(void) const;
        int     toInt(void) const;

};

std::ostream    &operator<<(std::ostream &oStream, Fixed const &nInt);

#endif