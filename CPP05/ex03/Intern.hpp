#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern& copy);
        Intern& operator=(const Intern& copy);
        ~Intern() {}

        AForm* makeForm(const std::string& formName, const std::string& target);

        class FormNotFoundException : public std::exception {
        public:
            const char* what() const throw() {
                return "Intern could not find that form";
            }
        };

};

#endif