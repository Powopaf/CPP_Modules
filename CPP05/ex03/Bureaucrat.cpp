#include "Bureaucrat.hpp"
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm& form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}	

void Bureaucrat::executeForm(const AForm& form) {
	try {
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat) {
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return out;
}
