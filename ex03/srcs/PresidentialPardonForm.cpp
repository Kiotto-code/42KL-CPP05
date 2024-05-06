/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 23:35:07 by yichan            #+#    #+#             */
/*   Updated: 2024/05/07 02:02:23 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute), _target("")
{
	std::cout << "[PresidentialPardonForm] default constructor was being called " << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(void) 
{
	std::cout << "[PresidentialPardonForm] destructor was being called " << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) 
	: AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute), _target(target) {
	std::cout << "[PresidentialPardonForm] default constructor w string was being called " << std::endl;
	}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) 
	: AForm("PresidentialPardonForm", PresidentialPardonForm::gradeToSign, PresidentialPardonForm::gradeToExecute), _target(src.getTarget()) {
	std::cout << "[PresidentialPardonForm] copy constructor was being called " << std::endl;
	}

const std::string&		PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
};

PresidentialPardonForm	&PresidentialPardonForm::operator = (const PresidentialPardonForm &src)
{
	// AForm::operator=(src);
	this->_target = src._target;
	std::cout << "[PresidentialPardonForm] assignment operator was being called" << std::endl;
	return (*this);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkExecute(executor);
	std::cout << MAGENTA << getDataType(executor) << " " << RESET << executor.getName() << " executed " << _target << std::endl;
	// std::cout << MAGENTA << typeid(executor).name() << " " << RESET << executor.getName() << " executed " << _target << std::endl;
	std::cout << "* loud drilling noise *" << std::endl;
	srand(time(0));
	if (std::rand() % 2)
		std::cout << this->_target << RED" has been robotomized."RESET << std::endl;
	else
		std::cout << "Robotomy has failed." << std::endl;
}