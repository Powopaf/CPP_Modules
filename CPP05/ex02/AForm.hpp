#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <exception>
#include <iostream>

class Bureaucrat;

class AForm {
    private:
        std::string name;
        bool sign;
        int gradeToSign;
        int gradeToExecute;
        AForm();
    public:
        AForm(const std::string& name, int gradeTosign, int gradeToExecute);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& copy);
        ~AForm() {}

        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);

        virtual void execute(const Bureaucrat& executor) const = 0;

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
        class FormNotSignedException : public std::exception {
            public:
                const char* what() const throw() {
                    return "Form is not signed";
                }
        };
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
