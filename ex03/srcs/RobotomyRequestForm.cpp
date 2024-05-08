/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:41:01 by yichan            #+#    #+#             */
/*   Updated: 2024/05/08 16:35:39 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), _target("")
{
	std::cout << "[RobotomyRequestForm] default constructor was being called " << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(void) 
{
	std::cout << "[RobotomyRequestForm] destructor was being called " << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) 
	: AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), _target(target) {
	std::cout << "[RobotomyRequestForm] default constructor w string was being called " << std::endl;
	}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) 
	: AForm("RobotomyRequestForm", RobotomyRequestForm::gradeToSign, RobotomyRequestForm::gradeToExecute), _target(src.getTarget()) {
	std::cout << "[RobotomyRequestForm] copy constructor was being called " << std::endl;
	}

const std::string&		RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
};

RobotomyRequestForm	&RobotomyRequestForm::operator = (const RobotomyRequestForm &src)
{
	// AForm::operator=(src);
	this->_target = src._target;
	std::cout << "[RobotomyRequestForm] assignment operator was being called" << std::endl;
	return (*this);
}

// void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
// {
// 	this->checkExecute(executor);
// 	std::cout << MAGENTA << getDataType(executor) << " " << RESET << executor.getName() << " executed " << _target << std::endl;
// 	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
// }

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
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