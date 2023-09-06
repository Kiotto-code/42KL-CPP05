/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 23:37:05 by yichan            #+#    #+#             */
/*   Updated: 2023/09/06 21:30:57 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Bureaucrat		Batman("Batman", 1);
	Bureaucrat		Flash("Flash", 40);
	Bureaucrat		Superman("Superman", 150);
	AForm			*form = NULL;

	std::cout << "\nUnsigned presidential pardon form" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28A");
		form->execute(Batman);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nSign and execute a presidential pardon form" << std::endl;
	try
	{
		form = new PresidentialPardonForm("28A");
		form->beSigned(Batman);
		form->execute(Batman);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nSign and execute robotomy request form with different people" << std::endl;
	try
	{
		form = new RobotomyRequestForm("28B");
		Batman.signForm(*form);
		std::cout << std::endl;
		Flash.executeForm(*form);
		Flash.executeForm(*form);
		Flash.executeForm(*form);
		Flash.executeForm(*form);
		Flash.executeForm(*form);
		Flash.executeForm(*form);
		Flash.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nUnauthorized bureaucrat" << std::endl;
	try
	{
		form = new ShrubberyCreationForm("28C");
		Batman.signForm(*form);
		Flash.executeForm(*form);
		Superman.executeForm(*form);
		delete form;
		form = NULL;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	system("leaks -q a.out");
	return 0;
}
