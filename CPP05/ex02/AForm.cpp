#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string& name, int gradeTosign, int gradeToExecute) {
    if (gradeTosign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeTosign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    this->name = name;
    this->gradeToSign = gradeTosign;
    this->gradeToExecute = gradeToExecute;
    this->sign = false;
}

Form::Form(const Form& copy) {
    *this = copy;
}

Form& Form::operator=(const Form& copy) {
    if (this == &copy)
        return *this;
    this->name = copy.name;
    this->sign = copy.sign;
    this->gradeToSign = copy.gradeToSign;
    this->gradeToExecute = copy.gradeToExecute;
    this->sign = copy.sign;
    return *this;
}
const std::string& Form::getName() const {

    return name;
}

int Form::getGradeToSign() const {
    return gradeToSign;
}

int Form::getGradeToExecute() const {
    return gradeToExecute;
}

bool Form::isSigned() const {
    return sign;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw Form::GradeTooLowException();
    sign = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return out;
}