#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class   Fixed
{
    private:
        int                 _fixedPointValue;
        static const int    _fractionalBits = 8;

    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed   &operator=(const Fixed &rhs);
        int     getRawBits(void) const;
        void    setRawBits(int const raw);

};

#endif