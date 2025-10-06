#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string input) : _input(input) {}

RPN::RPN(RPN const &copy) : _input(copy._input), _nb(copy._nb) {}

RPN &RPN::operator=(RPN const &copy) {
    if (this != &copy) {
        this->_input = copy._input;
        this->_nb = copy._nb;
    } return *this;
}

RPN::~RPN() {}

int RPN::calculate() {
    std::istringstream iss(_input);
    std::string token;

    while (iss >> token) {
        if (token.length() == 1 && std::isdigit(token[0])) {
            _nb.push(token[0] - '0');
        } else if (token.length() > 1) {
            bool all_digits = true;
            for (size_t i = 0; i < token.length(); ++i) {
                if (!std::isdigit(token[i])) {
                    all_digits = false;
                    break;
                }
            }
            if (all_digits)
                throw std::runtime_error("Error");
            else {
                throw std::runtime_error("Error");
            }
        }
        else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (_nb.size() < 2)
                throw std::runtime_error("Error");
            int b = _nb.top(); _nb.pop();
            int a = _nb.top(); _nb.pop();
            if (token == "+")
                _nb.push(a + b);
            else if (token == "-")
                _nb.push(a - b);
            else if (token == "*")
                _nb.push(a * b);
            else {
                if (b == 0)
                    throw std::runtime_error("Error");
                _nb.push(a / b);
            }
        } else {
            throw std::runtime_error("Error");
        }
    }
    if (_nb.size() != 1)
        throw std::runtime_error("Error");
    return _nb.top();
}