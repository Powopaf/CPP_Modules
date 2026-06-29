#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
    try {
        Bureaucrat bureaucrat(1, "John");
        Intern intern;
        AForm* forms[3];

        forms[0] = intern.makeForm("shrubbery creation", "Garden");
        forms[1] = intern.makeForm("robotomy request", "Bob");
        forms[2] = intern.makeForm("presidential pardon", "Alice");

        for (int i = 0; i < 3; ++i) {
            bureaucrat.signForm(*forms[i]);
            bureaucrat.executeForm(*forms[i]);
            delete forms[i];
        }

        try {
            intern.makeForm("invalid form", "Nobody");
        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}