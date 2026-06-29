#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

AForm* createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}

Intern::Intern() {}

Intern::Intern(const Intern& copy) {
    *this = copy;
}

Intern& Intern::operator=(const Intern& copy) {
    if (this == &copy)
        return *this;
    return *this;
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    struct FormEntry {
        const char* name;
        AForm* (*creator)(const std::string& target);
    };

    static const FormEntry forms[] = {
        { "shrubbery creation", &createShrubbery },
        { "robotomy request", &createRobotomy },
        { "presidential pardon", &createPresidential }
    };

    for (size_t i = 0; i < sizeof(forms) / sizeof(forms[0]); ++i) {
        if (formName == forms[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i].creator(target);
        }
    }
    throw Intern::FormNotFoundException();
}