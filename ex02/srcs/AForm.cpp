#include "AForm.hpp"

AForm::AForm( void ) : m_name("Blank"), m_signState(false), m_signGrade(150), m_executeGrade(150)
{
	std::cout << "[AForm] constructor was being called" << std::endl;
};

AForm::AForm (const std::string &name, const int sign_grade, const int execute_grade)
: m_name(name), m_signState(false), m_signGrade(sign_grade), m_executeGrade(execute_grade)
{
	std::cout << "[AForm] constructor with data was being called" << std::endl;
	if (sign_grade < Bureaucrat::highestGrade || execute_grade < Bureaucrat::highestGrade )
		throw (AForm::GradeTooHighException());
	if (sign_grade > Bureaucrat::lowestGrade || execute_grade > Bureaucrat::lowestGrade)
		throw (AForm::GradeTooLowException());
	return ;
};

AForm::AForm(const AForm &other) : m_name(other.m_name), m_signGrade(other.m_signGrade), m_executeGrade(other.m_executeGrade)
{
	this->m_signState = other.m_signState;
}

AForm::~AForm()
{};

AForm	&AForm::operator = (const AForm &other)
{
	if (this == &other)
		return (*this);
	this->m_signState = other.m_signState;
	return (*this);
};

const	std::string	&AForm::getName( void ) const
{
	return (this->m_name);
}

bool		AForm::getSign_state( void ) const
{
	return (this->m_signState);
}

int			AForm::getSign_grade( void ) const
{
	return (this->m_signGrade);
}

int			AForm::getExecute_grade( void ) const
{
	return (this->m_executeGrade);
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->m_signState)
		throw (AForm::AlreadySignedException());
	if (bureaucrat.getGrade() > this->m_signGrade)
		throw (AForm::GradeTooLowException());
	this->m_signState = true;
	return ;
}

void	AForm::checkExecute(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > m_executeGrade)
		throw GradeTooLowException();
	if (!this->m_signState)
		throw InvalidFormException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "Grade Signed";
}
const char* AForm::InvalidFormException::what() const throw()
{
	return "This form haven't signed and cannot be executed \n";
}

std::ostream &operator<< (std::ostream &os, const AForm &doc)
{
	os << "\"" << doc.getName() << "\" ["
		<< (doc.getSign_state() ? "signed" : "unsigned") << "] "
		<< ";to sign: " << doc.getSign_grade()
		<< "; to execute: " << doc.getExecute_grade() << ")";
	return (os);
}