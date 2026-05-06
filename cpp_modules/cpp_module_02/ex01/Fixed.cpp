#include "Fixed.hpp"

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int num)
{
    std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
    std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(num * (1 << _fractionalBits));
}

Fixed   &Fixed::operator=(const Fixed &rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_fixedPointValue = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits(void) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return (this->_fixedPointValue);
}

void    Fixed::setRawBits(int const raw)
{
    // std::cout << "setRawBits member function called" << std::endl;
    this->_fixedPointValue = raw;
}

float   Fixed::toFloat(void) const
{
    return (static_cast<float>(this->getRawBits()) / (1 << _fractionalBits));
}

int Fixed::toInt(void) const
{
    return (_fixedPointValue >> _fractionalBits);
}

std::ostream    &operator<<(std::ostream &oStream, Fixed const &nInt)
{
    return (oStream << nInt.toFloat());
}
