#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>
#include <limits>

void validateInput(char **av)
{
    for (size_t i = 1; av[i]; ++i) {
        // std::string s(av[i]);
        std::stringstream ss(av[i]);
        long value;
        ss >> value;

        if (value <= 0 || value > std::numeric_limits<int>::max()) {
            std::cout << "value: " << value << ", i: " << i << ", number: " << av[i] << std::endl;
            throw std::runtime_error("Input error");
        }
            
    }
}

void printUnsorted(char **av)
{
    std::cout << "Before: ";
    for (size_t i = 1; av[i]; ++i)
        std::cout << av[i] << " ";
    std::cout << std::endl;
}

template<typename Container>
void printContainer(const Container &data)
{
    size_t size = data.size();
    for (size_t i = 0; i < size; ++i)
        std::cout << data[i] << " ";
    std::cout << std::endl;
}

int main (int ac, char **av)
{


    try {
        
        if (ac < 2) {
            throw std::runtime_error("Input Error");
        }
        validateInput(av);
        printUnsorted(av);
        PmergeMe<std::vector<int>> vectorSorter;
        vectorSorter.sort(av);
        PmergeMe<std::deque<int>> dequeSorter;
        dequeSorter.sort(av);
        const std::vector<int> vectorSorted = vectorSorter.getSorted();
        const std::deque<int> dequeSorted = dequeSorter.getSorted();
        for (int i = 0; i < ac - 1; ++i) {
            if (vectorSorted[i] != dequeSorted[i])
                throw std::runtime_error("Sorting mismatch between containers vector and deque");
        }
        std::cout << "Integers after sorting: ";
        printContainer(vectorSorted);
        std::cout   << "Both containers - vector and deque have sorted " << ac - 1 << " integers successfully" << std::endl;
        std::cout   << "Time taken by vector: " << vectorSorter.getTime() << std::endl
                    << "Number of comparisons by vector: " << vectorSorter.getComparisons() << std::endl
                    << "Time taken by deque: " << dequeSorter.getTime() << std::endl
                    << "Number of comparisons by deque: " << dequeSorter.getComparisons() << std::endl;
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}