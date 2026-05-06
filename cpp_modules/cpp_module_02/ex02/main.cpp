/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsewlia <dsewlia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 21:06:40 by dsewlia           #+#    #+#             */
/*   Updated: 2025/06/24 22:29:38 by dsewlia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed   a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << "\nADDITIONAL TESTS\n" << std::endl;
    std::cout << "a : " << a << std::endl;
    std::cout << "b : " << b << std::endl;
    bool    temp;
    temp = a > b;
    std::cout << "a > b : " << temp << std::endl;
    temp = a < b;
    std::cout << "a < b : " << temp << std::endl;
    temp = a >= b;
    std::cout << "a >= b : " << temp << std::endl;
    temp = a <= b;
    std::cout << "a <= b : " << temp << std::endl;
    temp = a == b;
    std::cout << "a == b : " << temp << std::endl;
    temp = a != b;
    std::cout << "a != b : " << temp << std::endl;
    std::cout << "Max of a and b : " << Fixed::max(a, b) << std::endl;
    std::cout << "Min of a and b : " << Fixed::min(a, b) << std::endl;
    std::cout << "--a : " << --a << std::endl;
    std::cout << "a-- : " << a-- << std::endl;
    return (0);
}
