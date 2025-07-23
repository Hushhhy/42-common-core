#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : N(N) {}

Span::Span(Span const &copy) {
    *this = copy;
}

Span &Span::operator=(Span const &copy) {
    if (this != &copy) {
        this->N = copy.N;
        this->num = copy.num;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(unsigned int nb) {
    if (num.size() < N)
        num.push_back(nb);
    else
        throw std::runtime_error("Maximum size reached");
}

int Span::shortestSpan() {
    if (num.size() < 2)
        throw std::runtime_error("Minimum 2 numbers required");
    std::vector<int> sorted = num;
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() {
    if (num.size() < 2)
        throw std::runtime_error("Minimum 2 numbers required");
    std::vector<int> sorted = num;
    std::sort(sorted.begin(), sorted.end());
    return sorted.back() - sorted.front();
}