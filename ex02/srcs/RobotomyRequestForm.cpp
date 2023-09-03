/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:41:01 by yichan            #+#    #+#             */
/*   Updated: 2023/09/03 22:41:12 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target("")
{
	std::cout << "[RobotomyRequestForm] default constructor was being called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target(target) {
	std::cout << "[RobotomyRequestForm] default constructor w string was being called " << std::endl;
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) 
	: AForm("RobotomyRequestForm", gradeToSign, gradeToExecute), _target(src.getTarget()) {
	std::cout << "[RobotomyRequestForm] copy constructor was being called " << std::endl;
	}

const std::string&		RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
};

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
	AForm::operator=(src);
	this->_target = src._target;
	std::cout << "[RobotomyRequestForm] assignment operator was being called" << std::endl;
	return (*this);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	this->checkExecute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}