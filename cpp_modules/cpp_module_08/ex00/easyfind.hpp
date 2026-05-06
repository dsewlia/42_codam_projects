#include <algorithm>
#include <iterator>

template <typename T>
auto easyfind(T &&container, const int n)
	->decltype(std::begin(container))
	{
		auto it = std::begin(container);
		auto end = std::end(container);
		for (; it != end; ++it)
			if (*it == n)
				break;
		return it;
	}