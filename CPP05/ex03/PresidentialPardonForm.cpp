#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
: AForm("Presidential Pardon Form", 25, 5) {
    this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy)
: AForm(copy) {
    this->target = copy.target;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy) {
    if (this == &copy) {
        return *this;
    }
    AForm::operator=(copy);
    target = copy.target;
    return *this;
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}