#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(float x, float y) : _x(x), _y(y) {}

Point::Point(const Point &p) : _x(p._x), _y(p._y) {}

Point::~Point() {}

Point   &Point::operator=(const Point &rhs)
{
    if (this != &rhs)
    {
        (Fixed)this->_x = rhs._x;
        (Fixed)this->_y = rhs._y;
    }
    return (*this);
}
Fixed   Point::getX(void) const
{
    return (this->_x);
}

Fixed   Point::getY(void) const
{
    return (this->_y);
}
