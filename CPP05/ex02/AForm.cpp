#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, int gradeTosign, int gradeToExecute) {
    if (gradeTosign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeTosign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    this->name = name;
    this->gradeToSign = gradeTosign;
    this->gradeToExecute = gradeToExecute;
    this->sign = false;
}

AForm::AForm(const AForm& copy) {
    *this = copy;
}

AForm& AForm::operator=(const AForm& copy) {
    if (this == &copy)
        return *this;
    this->name = copy.name;
    this->sign = copy.sign;
    this->gradeToSign = copy.gradeToSign;
    this->gradeToExecute = copy.gradeToExecute;
    this->sign = copy.sign;
    return *this;
}
const std::string& AForm::getName() const {

    return name;
}

int AForm::getGradeToSign() const {
    return gradeToSign;
}

int AForm::getGradeToExecute() const {
    return gradeToExecute;
}

bool AForm::isSigned() const {
    return sign;
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > gradeToSign)
        throw AForm::GradeTooLowException();
    sign = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& form) {
    out << "Form: " << form.getName() << ", signed: " << (form.isSigned() ? "yes" : "no") << ", grade to sign: " << form.getGradeToSign() << ", grade to execute: " << form.getGradeToExecute();
    return out;
}