/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 23:37:05 by yichan            #+#    #+#             */
/*   Updated: 2024/05/06 23:18:59 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// int main()
// {
// 	Bureaucrat		Batman("Batman", 1);
// 	Bureaucrat		Flash("Flash", 40);
// 	Bureaucrat		Superman("Superman", 150);
// 	AForm			*form = NULL;

// 	std::cout << "\nUnsigned presidential pardon form" << std::endl;
// 	try
// 	{
// 		form = new PresidentialPardonForm("28A");
// 		form->execute(Batman);
// 		delete form;
// 		form = NULL;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}

// 	std::cout << "\nSign and execute a presidential pardon form" << std::endl;
// 	try
// 	{
// 		form = new PresidentialPardonForm("28A");
// 		form->beSigned(Batman);
// 		form->execute(Batman);
// 		delete form;
// 		form = NULL;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}

// 	std::cout << "\nSign and execute robotomy request form with different people" << std::endl;
// 	try
// 	{
// 		form = new RobotomyRequestForm("28B");
// 		Batman.signForm(*form);
// 		std::cout << std::endl;
// 		Flash.executeForm(*form);
// 		Flash.executeForm(*form);
// 		Flash.executeForm(*form);
// 		Flash.executeForm(*form);
// 		Flash.executeForm(*form);
// 		Flash.executeForm(*form);
// 		Flash.executeForm(*form);
// 		delete form;
// 		form = NULL;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}

// 	std::cout << "\nUnauthorized bureaucrat" << std::endl;
// 	try
// 	{
// 		form = new ShrubberyCreationForm("28C");
// 		Batman.signForm(*form);
// 		Flash.executeForm(*form);
// 		Superman.executeForm(*form);
// 		delete form;
// 		form = NULL;
// 	}
// 	catch (std::exception &e)
// 	{
// 		std::cout << "Exception: " << e.what() << std::endl;
// 	}
// 	system("leaks -q a.out");
// 	return 0;
// }


static void cterm(void)
{
	std::cin.get();
	std::cout << "\e[1;1H\e[2J";
}

void	testInternFormCreation(std::string formName, std::string target)
{
	std::cout << std::endl << "---- Creating form \"" << formName
		<< "\" with target \"" << target << "\":" << std::endl;
	Intern	lowlyIntern = Intern();
	Bureaucrat bigBoss("Big Boss Barry", 1);
	AForm *	form;
	try
	{
		form = lowlyIntern.makeForm(formName, target);
		std::cout << GOLD"SIGNING FORM"RESET << std::endl;
		bigBoss.signForm(*form);
		std::cout << GOLD"EXCUTING FORM"RESET << std::endl;
		bigBoss.executeForm(*form);
		delete (form);
	}
	catch (std::exception & e)
	{
		std::cout << RED ": " << e.what() << RESET << std::endl;
	}
}

int	main(void)
{
	std::string const	shrubberyFormName = "shrubbery creation";
	std::string const	robotomyFormName = "robotomy request";
	std::string const	presidentialFormName = "presidential pardon";

	testInternFormCreation(shrubberyFormName, "Garden");
	cterm();
	testInternFormCreation(robotomyFormName, "Unsuspecting Customer");
	cterm();
	testInternFormCreation(presidentialFormName, "Jesus");
	cterm();
	testInternFormCreation("Bad Form Name", "Mr. X");
	cterm();
	testInternFormCreation("", "");	
	// system("leaks -q a.out");
	return (0);
}
