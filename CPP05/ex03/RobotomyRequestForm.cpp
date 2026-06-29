#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
: AForm("Robotomy Request Form", 72, 45) {
    this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy)
: AForm(copy) {
    this->target = copy.target;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy) {
    if (this == &copy) {
        return *this;
    }
    AForm::operator=(copy);
    target = copy.target;
    return *this;
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!isSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::cout << "Bzzzz... Bzzzz... Drilling noises..." << std::endl;
    if (rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << target << "." << std::endl;
}