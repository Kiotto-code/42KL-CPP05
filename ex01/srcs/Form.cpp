#include "Form.hpp"

Form::Form( void ) : m_name("Blank"), m_signState(false), m_signGrade(150), m_executeGrade(150)
{
	std::cout << "[Form] constructor was being called" << std::endl;
};

Form::Form (const std::string &name, const int sign_grade, const int &execute_grade)
: m_name(name), m_signState(false), m_signGrade(sign_grade), m_executeGrade(execute_grade)
{
	std::cout << "[Form] constructor with data was being called" << std::endl;
	if (sign_grade < Bureaucrat::highestGrade || execute_grade < Bureaucrat::highestGrade )
		throw (Form::GradeTooHighException());
	if (sign_grade > Bureaucrat::lowestGrade || execute_grade > Bureaucrat::lowestGrade)
		throw (Form::GradeTooLowException());
	return ;
};

Form::Form(const Form &other) : m_name(other.m_name), m_signGrade(other.m_signGrade), m_executeGrade(other.m_executeGrade)
{
	this->m_signState = other.m_signState;
}

Form::~Form()
{};

Form	&Form::operator = (const Form &other)
{
	if (this == &other)
		return (*this);
	this->m_signState = other.m_signState;
	return (*this);
};

const	std::string	&Form::getName( void ) const
{
	return (this->m_name);
}

bool		Form::getSign_state( void ) const
{
	return (this->m_signState);
}

int			Form::getSign_grade( void ) const
{
	return (this->m_signGrade);
}

int			Form::getExecute_grade( void ) const
{
	return (this->m_executeGrade);
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (this->m_signState)
		throw (Form::AlreadySignedException());
	if (bureaucrat.getGrade() > this->m_signGrade)
		throw (Form::GradeTooLowException());
	this->m_signState = true;
	return ;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade Too High\n";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade Too Low\n";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "Grade Signed\n";
}

std::ostream &operator<< (std::ostream &os, const Form &doc)
{
	os << "\"" << doc.getName() << "\" ["
		<< (doc.getSign_state() ? "signed" : "unsigned") << "] "
		<< ";to sign: " << doc.getSign_grade()
		<< "; to execute: " << doc.getExecute_grade() << ")";
	return (os);
}
