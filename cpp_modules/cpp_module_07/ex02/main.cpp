#include <iostream>
#include "Array.hpp"

int main()
{
    try
    {
        // Default constructor
        Array<int> arr1;
        std::cout << "arr1 size: " << arr1.size() << std::endl;

        // Parameterized constructor
        Array<int> arr2(5);
        std::cout << "arr2 size: " << arr2.size() << std::endl;

		std::cout << arr2[2] << std::endl;
        // Fill arr2
        for (size_t i = 0; i < arr2.size(); i++)
            arr2[i] = static_cast<int>(i * 10);

        std::cout << "arr2 contents: ";
        for (size_t i = 0; i < arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << std::endl;

        // Copy constructor
        Array<int> arr3(arr2);
        std::cout << "arr3 (copy of arr2) contents: ";
        for (size_t i = 0; i < arr3.size(); i++)
            std::cout << arr3[i] << " ";
        std::cout << std::endl;

        // Copy assignment
        Array<int> arr4 = arr2;
        std::cout << "arr4 (assigned from arr2) contents: ";
        for (size_t i = 0; i < arr4.size(); i++)
            std::cout << arr4[i] << " ";
        std::cout << std::endl;

        // Test index out of bounds exception
        std::cout << "Accessing arr2[10] (out of bounds)..." << std::endl;
        std::cout << arr2[10] << std::endl; // This should throw

    }
    catch (const Array<int>::IndexOutOfBoundException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
