#pragma once

#include <vector>
#include <exception>
#include <iostream>
#include <limits>
#include <random>
#include <algorithm>
#include <iostream>
#include <unordered_set>

class Span
{
	private:
		unsigned int _maxSize;
		std::vector<int> _numbers;
		int _minValue;
		int _maxValue;

	public:
		explicit Span(unsigned int N);
		Span(const Span &rhs);
		Span &operator=(const Span &rhs);
		~Span();

	class ContainerFullException : public std::exception
	{
		const char *what() const noexcept override;
	};

	class NotEnoughNumbersException : public std::exception
	{
		const char *what() const noexcept override;
	};

	void addNumber(int numb);

	template<typename InputIt>
	void addNumber(InputIt begin, InputIt end) {
		auto toAdd = std::distance(begin, end);
		if (_maxSize < _numbers.size() + toAdd)
			throw ContainerFullException();
		for (auto it = begin; it != end; ++it)
			addNumber(*it);
	}
	uint64_t shortestSpan() const;
	uint64_t longestSpan() const;
	void addManyRandomNumbers(int min, int max, int n);
	void printDetails() const;
	void printNumbers() const;
};