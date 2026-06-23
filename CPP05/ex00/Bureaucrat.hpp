#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
	Bureaucrat();
	Bureaucrat(int grade);
	Bureaucrat(const Bureaucrat& copy);
	Bureaucrat& operator=(const Bureaucrat& copy);
	~Bureaucrat();

	const std::string& getName() const;
	int getGrade() const;
};

#endif
