/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:20:58 by yichan            #+#    #+#             */
/*   Updated: 2023/08/31 15:53:08 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Default_constructor"){
	std::cout << "[Bureaucrat] default constructor being called" << std::endl;
}

// Bureaucrat::Bureaucrat(std::string name) : _name(name)
// {
// 	std::cout << "[Bureaucrat] constructor with name str being called" << std::endl;
// }

Bureaucrat::Bureaucrat(std::string const & name, int grade)
	: _name(name), _grade(Bureaucrat::lowestGrade)
{
	std::cout << CYAN "[Bureaucrat] " << name << " constructor called." RESET << std::endl;
	if (grade < Bureaucrat::highestGrade)
		throw(Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::lowestGrade)
		throw(Bureaucrat::GradeTooLowException());
	else
		this->_grade = grade;
	return ;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << "[Bureaucrat] copy constructor with name str being called" << std::endl;
}

Bureaucrat &Bureaucrat::operator = (const Bureaucrat &other)
{
	std::cout << CYAN "Bureaucrat assignment operator overload called."
		RESET << std::endl;
	if (this == &other)
		return (*this);
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "[Bureaucrat] destructor being called" << std::endl;
};

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat grade is too low";
}

const std::string	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade(void)
{
	Bureaucrat::incrementGrade(1);
}

void	Bureaucrat::decrementGrade(void)
{
	Bureaucrat::decrementGrade(1); 
}

void	Bureaucrat::incrementGrade(int n)
{
	if (this->_grade - n < Bureaucrat::highestGrade)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << GREEN << *this << " was promoted " << n << " level from "
		<< this->_grade << " to " << this->_grade - n << " !" << RESET << std::endl;

		this->_grade -= n;
	}
}

void	Bureaucrat::decrementGrade(int n)
{
	if (this->_grade + n > Bureaucrat::lowestGrade)
		throw Bureaucrat::GradeTooLowException();
	else
	{
		std::cout << GREEN << *this << " was demoted " << n << " level from "
		<< this->_grade << " to " << this->_grade + n << " !" << RESET << std::endl;

		this->_grade += n;
	}
}

void	Bureaucrat::signForm(Form & document) const
{
	try
	{
		document.beSigned(*this);
		std::cout << GREEN << *this << " signed " << document << RESET << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << RED << *this << " couldn't sign " << document << " because: "
			<< e.what() << RESET << std::endl;
	}
	
}



std::ostream &operator << (std::ostream &os , const Bureaucrat &other)
{
	return os << other.getName() << ", bureaucrat grade " << other.getGrade();
}
