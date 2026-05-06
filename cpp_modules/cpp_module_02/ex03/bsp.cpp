#include "Point.hpp"

static Fixed abs(Fixed x)
{
    if (x < 0)
        return (x * -1);
    return (x);
}

static Fixed area(const Point a, const Point b, const Point c)
{
    return (abs(((a.getX() * (b.getY() - c.getY())) + (b.getX() * (c.getY() - a.getY())) + (c.getX() * (a.getY() - b.getY()))) / 2));
}

bool    bsp(const Point a, const Point b, const Point c, const Point point)
{
    Fixed   totalArea = area(a, b, c);
    Fixed   pABArea = area(point, a, b);
    Fixed   pACArea = area(point, a, c);
    Fixed   pBCArea = area(point, b, c);

    if (pABArea == 0 || pBCArea == 0 || pACArea == 0)
        return (false);
    return (totalArea == pABArea + pACArea + pBCArea);
}