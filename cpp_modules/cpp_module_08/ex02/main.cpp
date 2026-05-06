#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "\n*** Testing subject case ***" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n*** Testing it using list ***" << std::endl;
	std::list<int> l1;
	l1.push_back(5);
	l1.push_back(17);
	std::cout << l1.back() << std::endl;
	l1.pop_back();
	std::cout << l1.size() << std::endl;
	l1.push_back(3);
	l1.push_back(5);
	l1.push_back(737);
	//[...]
	l1.push_back(0);
	std::list<int>::iterator it1 = l1.begin();
	std::list<int>::iterator ite1 = l1.end();
	++it1;
	--it1;
	while (it1 != ite1)
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	std::stack<int, std::list<int>> s1(l1); 

	return 0;
}