#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <ctime>
#include <list>

class Span {
    private:
        unsigned int N;
        std::vector<int> num;
    public:
        Span();
        Span(unsigned int N);
        Span(Span const &copy);
        Span &operator=(Span const &copy);
        ~Span();

        void addNumber(unsigned int nb);

        template<typename Iterator>
        void addRange(Iterator begin, Iterator end);

        int shortestSpan();
        int longestSpan();
};

template<typename Iterator>
void Span::addRange(Iterator begin, Iterator end) {
    for (Iterator it = begin; it != end; ++it) {
        if (num.size() >= N)
            throw std::runtime_error("Maximum size reached");
        num.push_back(*it);
    }
}

#endif