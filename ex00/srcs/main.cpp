/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 20:28:10 by yichan            #+#    #+#             */
/*   Updated: 2024/05/08 15:56:46 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
void	printfException(std::string name, int grade)
{
	try
	{
		Bureaucrat bureaucrat(name, grade);
		std::cout << bureaucrat << " successfully created." << std::endl;
		return ;
	}
	catch(Bureaucrat::GradeTooHighException & e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
	catch(Bureaucrat::GradeTooLowException & e)
	{
		std::cerr << RED "Exception: " << e.what() << RESET << std::endl;
	}
}

int main(void)
{
	{
		std::cout << "test" << std::endl;
		printfException  ("aqua", 1);
		printfException  ("batman", 30);
		printfException  ("flash", 80);
		printfException  ("superman", 130);
		printfException  ("wonder", 150);
	}
	{
		Bureaucrat batman("batman", 100);
		Bureaucrat superman("superman", 10);

		std::cout << "Superman show grade : " << superman.getGrade() << std::endl;
		superman = batman;
		std::cout << "Superman show grade : " << superman.getGrade() << std::endl;
		
		batman.decrementGrade(50);
		superman.incrementGrade(50);

		{
			Bureaucrat *test;
			std::cout << GOLD"TEST THE INCREMENT"RESET << std::endl;
			test = new Bureaucrat("test", 100);
			test->decrementGrade(50);
			test->incrementGrade(50);
			delete test;
		}

		try
		{
			std::cout << GOLD"TEST THE EXCEED LOW BOUND"RESET << std::endl;
			std::cout << batman.getGrade() << std::endl;
			batman.decrementGrade(60);
		}
		catch(Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << e.what() << '\n';
		}
		
		try
		{
			std::cout << GOLD"TEST THE EXCEED HIGH BOUND"RESET << std::endl;
			std::cout << superman.getGrade() << std::endl;
			superman.incrementGrade(60);
		}
		catch(Bureaucrat::GradeTooHighException & e)
		{
			std::cerr << e.what() << '\n';
		}
		catch(Bureaucrat::GradeTooLowException & e)
		{
			std::cerr << e.what() << '\n';
		}
		system("leaks -q a.out");
	}
}
