#include "Span.hpp"

int main()
{
    std::cout << "=== MAN tests ===" << std::endl;
    try {
        Span sp = Span(5);

        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << sp.shortestSpan() << std::endl;  // 2
        std::cout << sp.longestSpan() << std::endl;   // 14
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 2: too many numbers ===" << std::endl;
    try {
        Span sp2 = Span(3);
        sp2.addNumber(1);
        sp2.addNumber(2);
        sp2.addNumber(3);
        sp2.addNumber(4);  // exception
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 3: less than 2 numbers ===" << std::endl;
    try {
        Span sp3 = Span(10);
        sp3.addNumber(42);
        sp3.shortestSpan();  // exception
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 4: Large numbers ===" << std::endl;
    try {
        Span sp4 = Span(4);
        sp4.addNumber(0);
        sp4.addNumber(1000000);
        sp4.addNumber(-500000);
        sp4.addNumber(2000000);

        std::cout << "Shortest span: " << sp4.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp4.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 5: vector===" << std::endl;
    try {
        std::vector<int> v;
        for (int i = 1; i <= 1000; ++i) {
            v.push_back(i * 2);  // Even numbers from 2 to 2000
        }
        
        Span sp6 = Span(1000);
        sp6.addRange(v.begin(), v.end());
        
        std::cout << "Shortest span: " << sp6.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp6.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 6: list ===" << std::endl;
    try {
        std::list<int> l;
        l.push_back(5);
        l.push_back(15);
        l.push_back(25);
        l.push_back(35);
        l.push_back(45);
        
        Span sp7 = Span(5);
        sp7.addRange(l.begin(), l.end());
        
        std::cout << "Shortest span: " << sp7.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp7.longestSpan() << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 7: range exceeds capacity ===" << std::endl;
    try {
        std::vector<int> v;
        for (int i = 1; i <= 10; ++i) {
            v.push_back(i);
        }
        
        Span sp8 = Span(5);
        sp8.addRange(v.begin(), v.end());  // 10 numbers
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== Test 8: Copy constructor test ===" << std::endl;
    try {
        Span original(3);
        original.addNumber(10);
        original.addNumber(20);
        original.addNumber(30);

        Span copy = original;
        std::cout << "Original shortest span: " << original.shortestSpan() << std::endl;
        std::cout << "Copy shortest span: " << copy.shortestSpan() << std::endl;
        std::cout << "Both should be the same: " << (original.shortestSpan() == copy.shortestSpan() ? "PASS" : "FAIL") << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}