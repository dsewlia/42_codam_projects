#include "RPN.hpp"

RPN::RPN() {}

void RPN::evaluate(const std::string &expression)
{
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token.length() == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/'))
        {
            if (_stack.size() < 2)
            {
                std::cerr << "Error" << std::endl;
                return;
            }
            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result = 0;

            if (token[0] == '+') result = a + b;
            else if (token[0] == '-') result = a - b;
            else if (token[0] == '*') result = a * b;
            else if (token[0] == '/')
            {
                if (b == 0)
                {
                    std::cerr << "Error" << std::endl;
                    return;
                }
                result = a / b;
            }
            _stack.push(result);
        }
        else if (token.length() == 1 && token[0] >= '0' && token[0] <= '9')
        {
            _stack.push(token[0] - '0');
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return;
        }
    }

    if (_stack.size() != 1)
    {
        std::cerr << "Error" << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}