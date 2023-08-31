#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main()
{
	try
	{
		Form a("a", 160, 140);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form b("b", 140, 0);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	Form form("Treaty", 50, 10);
	Bureaucrat alex("Kamala Harris", 60);
	Bureaucrat bob("Joe", 5);

	alex.signForm(form);
	std::cout << form << std::endl;
	
	bob.signForm(form);
	std::cout << form << std::endl;
	bob.signForm(form);
}