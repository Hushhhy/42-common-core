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