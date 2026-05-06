#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main()
{
	std::vector<int> v1 = {1,2,3,4,5};
	const std::vector<int> v2 = {6,7,8,9,10};
	std::list<int> l1 = {11,12,13,14,15};
	const std::list<int> l2 = {16,17,18,19,20};

	auto itV1a = easyfind(v1,3);
	auto itV1b = easyfind(v1,8);
	auto itV2a = easyfind(v2,8);
	auto itV2b = easyfind(v2,1);
	auto itL1a = easyfind(l1,13);
	auto itL1b = easyfind(l1,18);
	auto itL2a = easyfind(l2,18);
	auto itL2b = easyfind(l2,11);

	std::cout << std::endl << "*** Testing normal vector<int> ***" << std::endl;
	if (itV1a != v1.end())
		std::cout << "Found value in v1" << std::endl;
	else
		std::cout << "Value not found int v1" << std::endl;
	if (itV1b != v1.end())
		std::cout << "Found value in v1" << std::endl;
	else
		std::cout << "Value not found in v1" << std::endl;
	std::cout << std::endl << "*** Testing const vector<int> ***" << std::endl;
	if (itV2a != v2.end())
		std::cout << "Found value in v2" << std::endl;
	else
		std::cout << "Value not found int v2" << std::endl;
	if (itV2b != v2.end())
		std::cout << "Found value in v2" << std::endl;
	else
		std::cout << "Value not found int v2" << std::endl;
	std::cout << std::endl << "*** Testing normal list<int> ***" << std::endl;
	if (itL1a != l1.end())
		std::cout << "Found value in l1" << std::endl;
	else
		std::cout << "Value not found in l1" << std::endl;
	if (itL1b != l1.end())
		std::cout << "Found value in l1" << std::endl;
	else
		std::cout << "Value not found in l1" << std::endl;
	std::cout << std::endl << "*** Testing const list<int> ***" << std::endl;
	if (itL2a != l2.end())
		std::cout << "Found value in l2" << std::endl;
	else
		std::cout << "Value not found in l2" << std::endl;
	if (itL2b != l2.end())
		std::cout << "Found value in l2" << std::endl;
	else
		std::cout << "Value not found in l2" << std::endl;
	return 0;
}