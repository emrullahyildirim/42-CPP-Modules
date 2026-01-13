#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>

RPN::~RPN() {}
RPN::RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    (void)other;
    return *this;
}

int RPN::calc(const std::string &str) {
    std::stack<int> stack;

    for (size_t i = 0; i < str.length(); ++i) {
        char c = str[i];
        if (isspace(c))
            continue;

        if (isdigit(c))
            stack.push(c - '0');
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (stack.size() < 2)
                throw std::runtime_error("Error");

            int b = stack.top(); 
			stack.pop();
            int a = stack.top(); 
			stack.pop();

            if (c == '+') stack.push(a + b);
            else if (c == '-') stack.push(a - b);
            else if (c == '*') stack.push(a * b);
            else if (c == '/') {
                if (b == 0) throw std::runtime_error("Error");
                stack.push(a / b);
            }
        } 
		else
            throw std::runtime_error("Error");
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}