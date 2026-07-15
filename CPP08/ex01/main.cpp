#include "Span.hpp"
#include <iostream>

int main() {
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    // Test 1: Basic addNumber
    {
        Span s(5);
        s.addNumber(6);
        s.addNumber(3);
        s.addNumber(17);
        s.addNumber(9);
        s.addNumber(11);
        std::cout << "Test 1 - Added 5 numbers" << std::endl;
    }

    // Test 2: shortestSpan
    {
        Span s(5);
        s.addNumber(6);
        s.addNumber(3);
        s.addNumber(17);
        s.addNumber(9);
        s.addNumber(11);
        std::cout << "Test 2 - Shortest span: " << s.shortestSpan() << std::endl;
    }

    // Test 3: longestSpan
    {
        Span s(5);
        s.addNumber(6);
        s.addNumber(3);
        s.addNumber(17);
        s.addNumber(9);
        s.addNumber(11);
        std::cout << "Test 3 - Longest span: " << s.longestSpan() << std::endl;
    }

    // Test 4: NoPlaceException
    {
        Span s(2);
        s.addNumber(1);
        s.addNumber(2);
        try {
            s.addNumber(3);
        }
        catch (Span::NoPlaceException& e) {
            std::cout << "Test 4 - NoPlaceException caught: " << e.what() << std::endl;
        }
    }

    // Test 5: NoSpanException (less than 2 elements)
    {
        Span s(1);
        s.addNumber(42);
        try {
            s.shortestSpan();
        }
        catch (Span::NoSpanException& e) {
            std::cout << "Test 5 - NoSpanException caught: " << e.what() << std::endl;
        }
    }

    // Test 6: Copy constructor
    {
        Span s1(3);
        s1.addNumber(10);
        s1.addNumber(20);
        s1.addNumber(30);
        
        Span s2(s1);
        std::cout << "Test 6 - Copy constructor: shortest=" << s2.shortestSpan() << ", longest=" << s2.longestSpan() << std::endl;
    }

    // Test 7: Assignment operator
    {
        Span s1(3);
        s1.addNumber(5);
        s1.addNumber(15);
        s1.addNumber(25);
        
        Span s2(1);
        s2 = s1;
        std::cout << "Test 7 - Assignment operator: shortest=" << s2.shortestSpan() << ", longest=" << s2.longestSpan() << std::endl;
    }

    // Test 8: Large amount of numbers (10000+)
    {
        Span s(10000);
        for (int i = 0; i < 10000; i++) {
            s.addNumber(i);
        }
        std::cout << "Test 8 - Added 10000 numbers" << std::endl;
        std::cout << "         Shortest span: " << s.shortestSpan() << std::endl;
        std::cout << "         Longest span: " << s.longestSpan() << std::endl;
    }

    // Test 9: Using fill method
    {
        Span s(10000);
        s.fill();
        std::cout << "Test 9 - Filled with 10000 random numbers" << std::endl;
        std::cout << "         Shortest span: " << s.shortestSpan() << std::endl;
        std::cout << "         Longest span: " << s.longestSpan() << std::endl;
    }

    return 0;
}