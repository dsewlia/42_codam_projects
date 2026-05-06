#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <exception>
#include <iomanip>

class ScalarConverter
{
    public:
        ScalarConverter() = delete;
        ScalarConverter(const ScalarConverter&) = delete;
        ScalarConverter &operator=(const ScalarConverter&) = delete;
        ~ScalarConverter() = delete;

        static void convert(const std::string &str);
};