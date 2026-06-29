#ifndef ShrubberyCreationForm_HPP
#define ShrubberyCreationForm_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
    private:
        std::string target;
        ShrubberyCreationForm();
    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copy);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copy);
        ~ShrubberyCreationForm() {}

        void execute(const Bureaucrat& executor) const;

        class FileCreationException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Error: Could not create file";
                }
        };
    };

#endif