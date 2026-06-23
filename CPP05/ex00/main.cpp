#include "Bureaucrat.hpp"

int main() {
    {
        try {
            Bureaucrat b1(0, "John"); // This will throw GradeTooHighException
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        try {
            Bureaucrat b2(151, "Doe"); // This will throw GradeTooLowException
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        try {
            Bureaucrat b3(75, "Alice");
            std::cout << b3 << std::endl;
            b3.incrementGrade();
            std::cout << "After increment: " << b3 << std::endl;
            b3.decrementGrade();
            std::cout << "After decrement: " << b3 << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        try {
            Bureaucrat b4(1, "Bob");
            std::cout << b4 << std::endl;
            b4.incrementGrade(); // This will throw GradeTooHighException
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
    {
        try {
            Bureaucrat b5(150, "Charlie");
            std::cout << b5 << std::endl;
            b5.decrementGrade(); // This will throw GradeTooLowException
        }
        catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}