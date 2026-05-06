#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <string>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    void evaluate(const std::string &expression);
};

#endif