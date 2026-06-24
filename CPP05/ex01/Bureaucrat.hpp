#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>
#include <iostream>
#include <Form.hpp>

class Bureaucrat {
	private:
		std::string name;
		int grade;
		Bureaucrat();
	public:
	Bureaucrat(int grade, const std::string& name);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat() {}

	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void signForm(const Form& form);

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too high (highest grade is 1)";
			}
	};

	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too low (min 150)";
			}
	};
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
