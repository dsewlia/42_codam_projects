#include "iter.hpp"
#include <iostream>
#include <string>
#include <vector>


template <typename T>
void printAny(const T &a)
{
    std::cout << a << std::endl;
}

template <typename T>
void square(T &a)
{
    a = a * a;
}

int main()
{
    int arr1[] = {1 , 3, 5, 7, 9};
    double arr2[] = {1.1, 3.3, 5.5, 7.7, 9.9};
	std::vector<std::string> v = {"str1", "str2", "str3"};

	// std::cout << &v << std::endl;
	// std::cout << &v[0] << std::endl;
	// std::cout << &v[1] << std::endl;
	::iter(&v[0], 3, printAny<std::string>);
    ::iter(arr1, 5, printAny<int>);
    ::iter(arr2, 5, square<double>);
    ::iter(arr2, 5, printAny<double>);
    return 0;
}