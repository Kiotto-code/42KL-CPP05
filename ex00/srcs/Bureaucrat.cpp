/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:20:58 by yichan            #+#    #+#             */
/*   Updated: 2023/08/30 21:30:40 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
	std::cout << "[Bureaucrat] default constructor being called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	std::cout << "[Bureaucrat] constructor with name str being called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << "[Bureaucrat] copy constructor with name str being called" << std::endl;
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

const std::string	Bureaucrat::getName(void) const
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
	if (this->_grade - n < 1)
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
		if (this->_grade + n > 150)
		throw Bureaucrat::GradeTooHighException();
	else
	{
		std::cout << GREEN << *this << " was demoted " << n << " level from "
		<< this->_grade << " to " << this->_grade + n << " !" << RESET << std::endl;

		this->_grade += n;
	}
}




























Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &other)
{
	this->_grade = other._grade;
	// this->_name = other._name;
	return (*this);
}

std::ostream &operator << (std::ostream &os , const Bureaucrat &other)
{
	return os << other.getName() << ", bureaucrat grade " << other.getGrade();
}
