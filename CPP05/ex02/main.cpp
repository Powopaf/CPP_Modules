#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        Bureaucrat bureaucrat(1, "John");
        PresidentialPardonForm pardonForm("Alice");
        RobotomyRequestForm robotomyForm("Bob");
        ShrubberyCreationForm shrubberyForm("Garden");

        bureaucrat.signForm(pardonForm);
        bureaucrat.executeForm(pardonForm);

        bureaucrat.signForm(robotomyForm);
        bureaucrat.executeForm(robotomyForm);

        bureaucrat.signForm(shrubberyForm);
        bureaucrat.executeForm(shrubberyForm);
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}