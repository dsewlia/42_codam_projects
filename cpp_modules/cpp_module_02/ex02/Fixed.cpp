#include "Fixed.hpp"

Fixed::Fixed()
{
    // std::cout << "Default constructor called" << std::endl;
    _fixedPointValue = 0;
}

Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int num)
{
    // std::cout << "Int constructor called" << std::endl;
    this->_fixedPointValue = num << _fractionalBits;
}

Fixed::Fixed(const float num)
{
    // std::cout << "Float constructor called" << std::endl;
    this->_fixedPointValue = roundf(num * (1 << _fractionalBits));
}

Fixed   &Fixed::operator=(const Fixed &rhs)
{
    // std::cout << "Copy assignment operator called" << std::endl;
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

bool   Fixed::operator>(const Fixed rhs) const
{
    return (this->getRawBits() > rhs.getRawBits());
}

bool   Fixed::operator<(const Fixed rhs) const
{
    return (this->getRawBits() < rhs.getRawBits());
}

bool   Fixed::operator>=(const Fixed rhs) const
{
    return (this->getRawBits() >= rhs.getRawBits());
}

bool   Fixed::operator<=(const Fixed rhs) const
{
    return (this->getRawBits() <= rhs.getRawBits());
}

bool   Fixed::operator==(const Fixed rhs) const
{
    return (this->getRawBits() == rhs.getRawBits());
}

bool   Fixed::operator!=(const Fixed rhs) const
{
    return (this->getRawBits() != rhs.getRawBits());
}

Fixed  Fixed::operator+(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed  Fixed::operator-(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed  Fixed::operator*(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed  Fixed::operator/(const Fixed &rhs) const
{
    return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed  &Fixed::operator++(void)
{
    this->_fixedPointValue += 1;
    return (*this);
}

Fixed  Fixed::operator++(int)
{
    Fixed   temp(*this);
    this->_fixedPointValue += 1;
    return (temp);
}

Fixed  &Fixed::operator--(void)
{
    this->_fixedPointValue -= 1;
    return (*this);
}

Fixed  Fixed::operator--(int)
{
    Fixed   temp(*this);
    this->_fixedPointValue -=1;
    return (temp);
}

Fixed &Fixed::min(Fixed &lhs, Fixed &rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

const Fixed &Fixed::min(const Fixed &lhs, const Fixed &rhs)
{
    return (lhs.getRawBits() < rhs.getRawBits() ? lhs : rhs);
}

Fixed &Fixed::max(Fixed &lhs, Fixed &rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}
const Fixed &Fixed::max(const Fixed &lhs, const Fixed &rhs)
{
    return (lhs.getRawBits() > rhs.getRawBits() ? lhs : rhs);
}
