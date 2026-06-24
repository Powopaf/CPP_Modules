#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <Bureaucrat.hpp>

class Form {
    private:
        const std::string name;
        bool sign = false;
        const int gradeToSign;
        const int gradeToExecute;
        Form();
    public:
        Form(const std::string& name, int gradeTosign, int gradeToExecute);
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form() {}

        const std::string& getName() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;
        bool isSigned() const;
        void beSigned(const Bureaucrat& bureaucrat);

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

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
