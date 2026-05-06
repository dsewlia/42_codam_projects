#include "Span.hpp"
#include <iostream>

int main()
{
	try {
		std::cout << "\n*** Subject defined case ***\n" << std::endl;
		Span sp(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " <<sp.longestSpan() << std::endl << std::endl;
		sp.addNumber(15);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		std::cout << "\n*** Using range of iterators ***\n" << std::endl;
		std::vector<int> v1 = {6,3,17,9,11};
		Span sp1(5);
		sp1.addNumber(v1.begin(), v1.end());
		std::cout << "Shortest Span: " << sp1.shortestSpan() << std::endl;
		std::cout << "Longest Span: " <<sp1.longestSpan() << std::endl << std::endl;
		sp1.addNumber(15);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	try {
		Span spRandom(20000);
		spRandom.addManyRandomNumbers(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), 20000);
		std::cout << "\nRandom 20000 numbers are added\n\nBelow is the information" << std::endl;
		spRandom.printDetails();
		std::cout << "\nShortest Span: " << spRandom.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << spRandom.longestSpan() << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}