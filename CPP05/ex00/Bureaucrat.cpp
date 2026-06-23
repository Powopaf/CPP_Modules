#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(int grade, const std::string& name) {
	if (grade < 1) throw Bureaucrat::GradeTooHighException();
	if (grade > 150) throw Bureaucrat::GradeTooLowException();

	this->grade = grade;
	this->name = name;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy) {
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy) {
	if (this == &copy)
		return *this;
	Bureaucrat b = Bureaucrat(this->grade, this->name);
	return b;
}
