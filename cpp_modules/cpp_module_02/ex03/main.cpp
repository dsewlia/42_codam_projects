/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:06:40 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/24 23:18:13 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main(void)
{
    Point a(0, 0);
    Point b(10,0);
    Point c(0,10);
    Point p(3, 3);
    
    bool    result = bsp(a, b, c, p);
    if (result)
        std::cout << "point is in the triangle" << std::endl;
    else
        std::cout << "point is not in the triangle" << std::endl;
    return (0);
}
