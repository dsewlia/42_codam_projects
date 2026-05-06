#include "Span.hpp"

Span::Span(unsigned int N) : 
	_maxSize(N), _minValue(std::numeric_limits<int>::max()), _maxValue(std::numeric_limits<int>::min())
{
	_numbers.reserve(N + 10);
}

Span::Span(const Span &rhs) 
	: _maxSize(rhs._maxSize), _numbers(rhs._numbers),
	  _minValue(rhs._minValue), _maxValue(rhs._maxValue) {}

Span &Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_maxSize = rhs._maxSize;
		_numbers = rhs._numbers;
		_minValue = rhs._minValue;
		_maxValue = rhs._maxValue;
	}
	return *this;
}

Span::~Span()
{
	_numbers.clear();
}

const char *Span::ContainerFullException::what() const noexcept
{
	return "Container is full";
}

const char *Span::NotEnoughNumbersException::what() const noexcept
{
	return "Not enough numbers to calculate span!";
}

void Span::addNumber(int num)
{
	if (_numbers.size() >= _maxSize)
		throw ContainerFullException();
	_numbers.push_back(num);
	if (num < _minValue)
		_minValue = num;
	if (num > _maxValue)
		_maxValue = num;
}

uint64_t Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	uint64_t max = _maxValue;
	uint64_t min = _minValue;
	return max - min;
}

uint64_t Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();
	std::vector<int> temp = _numbers;
	std::sort(temp.begin(), temp.end());

	uint64_t shortest = std::numeric_limits<uint64_t>::max();
	uint64_t diff;
	for (size_t i = 1; i < temp.size(); ++i) {
		diff = temp[i] - temp[i - 1];
		if (diff < shortest)
			shortest = diff;
	}
	return shortest;
}

void Span::addManyRandomNumbers(int min, int max, int n)
{
    if (min >= max) {
		throw std::invalid_argument("min must be less than max");
	}
        
	if (static_cast<unsigned int>(n) > _maxSize - _numbers.size()) {
		throw std::invalid_argument("cannot load n number of int as the container will be overloaded");
	}
		
    uint64_t rangeSize = max - min;
    bool allowDuplicates = static_cast<unsigned int>(n) >= (rangeSize / 2);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max - 1);

    if (allowDuplicates) {
        // duplicates allowed → simple insert
        for (int i = 0; i < n; ++i) {
            addNumber(dist(gen));
        }
    } else {
        // no duplicates → use unordered_set for fast lookup
        std::unordered_set<int> existing(_numbers.begin(), _numbers.end());

        int count = 0;
        while (count < n) {
            int num = dist(gen);
            if (existing.find(num) != existing.end())
                continue; // skip duplicate
            addNumber(num);
            existing.insert(num);
            ++count;
        }
    }
}

void Span::printDetails() const
{
	std::cout << "\n\n *** Total numbers: " << _numbers.size() << " ***\n" << std::endl;
	std::cout << "\n\n *** min value: " << _minValue << " ***\n" << std::endl;
	std::cout << "\n\n *** max value: " << _maxValue << "***\n" << std::endl;
}

void Span::printNumbers() const
{
	std::cout << "/n *** Numbers (sperated by space) *** /n" << std::endl;
	for (size_t i = 0; i < _numbers.size(); ++i)
		std::cout << _numbers[i] << " ";
}
