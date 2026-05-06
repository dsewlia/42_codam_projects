#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed _x;
        const Fixed _y;

    public:
        Point();
        Point(float x, float y);
        Point(const Point &p);
        ~Point();
        Point &operator=(const Point &rhs);
        Fixed   getX(void) const;
        Fixed   getY(void) const;
};

bool bsp(Point a, Point b, Point c, Point point);

#endif