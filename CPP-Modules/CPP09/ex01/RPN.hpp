#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stdexcept>
#include <cstring>
#include <algorithm>
#include <exception>
#include <stack>

class RPN {
    private:
        std::string _input;
        std::stack<int> _nb;
    public:
        RPN();
        RPN(std::string _input);
        RPN(RPN const &copy);
        ~RPN();
        RPN &operator=(RPN const &copy);
};

#endif