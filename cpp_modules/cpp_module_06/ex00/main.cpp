#include "ScalarConverter.hpp"

int main(int argc, char** argv)
{
    for (int i = 1; i < argc; i++)
    {
        if (i != 1) {
            std::cout << std::endl;
        }
        ScalarConverter::convert(argv[i]);
    }
    return 0;
}