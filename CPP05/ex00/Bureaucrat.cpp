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
	this->grade = copy.grade;
	this->name = copy.name;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::incrementGrade() {
	if (grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade() {
	if (grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
