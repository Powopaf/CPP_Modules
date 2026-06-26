#include "Bureaucrat.hpp"
#include "Form.hpp"

#include <iostream>

int main() {
	{
		std::cout << "Bureaucrat constructor: valid grade" << std::endl;
		Bureaucrat bureaucrat(42, "Arthur");
		std::cout << bureaucrat << std::endl;
	}
    std::cout << std::endl;
	{
		std::cout << "Bureaucrat constructor: grade too high" << std::endl;
		try {
			Bureaucrat bureaucrat(0, "Zero");
			std::cout << bureaucrat << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Bureaucrat constructor: grade too low" << std::endl;
		try {
			Bureaucrat bureaucrat(151, "TooLow");
			std::cout << bureaucrat << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Bureaucrat increment/decrement" << std::endl;
		Bureaucrat bureaucrat(2, "Robin");
		std::cout << bureaucrat << std::endl;
		bureaucrat.incrementGrade();
		std::cout << bureaucrat << std::endl;
		bureaucrat.decrementGrade();
		std::cout << bureaucrat << std::endl;
	}
    std::cout << std::endl;
	{
		std::cout << "Bureaucrat increment at grade 1" << std::endl;
		try {
			Bureaucrat bureaucrat(1, "Top");
			bureaucrat.incrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Bureaucrat decrement at grade 150" << std::endl;
		try {
			Bureaucrat bureaucrat(150, "Bottom");
			bureaucrat.decrementGrade();
			std::cout << bureaucrat << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Form constructor and copy" << std::endl;
		Form form("TravelRequest", 50, 25);
		Form copy(form);
		std::cout << form << std::endl;
		std::cout << copy << std::endl;
	}
    std::cout << std::endl;
	{
		std::cout << "Form constructor: grade too high" << std::endl;
		try {
			Form form("InvalidHigh", 0, 25);
			std::cout << form << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Form constructor: grade too low" << std::endl;
		try {
			Form form("InvalidLow", 151, 25);
			std::cout << form << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Form signing: direct beSigned" << std::endl;
		Form form("Permit", 50, 25);
		Bureaucrat bureaucrat(45, "Alice");
		form.beSigned(bureaucrat);
		std::cout << form << std::endl;
	}
    std::cout << std::endl;
	{
		std::cout << "Form signing: rejected grade" << std::endl;
		Form form("Permit", 50, 25);
		Bureaucrat bureaucrat(75, "Bob");
		try {
			form.beSigned(bureaucrat);
			std::cout << form << std::endl;
		}
		catch (const std::exception& error) {
			std::cout << error.what() << std::endl;
		}
	}
    std::cout << std::endl;
	{
		std::cout << "Bureaucrat signForm helper" << std::endl;
		Form form("Application", 30, 20);
		Bureaucrat strong(10, "Strong");
		Bureaucrat weak(120, "Weak");
		strong.signForm(form);
		weak.signForm(form);
		std::cout << form << std::endl;
	}
}