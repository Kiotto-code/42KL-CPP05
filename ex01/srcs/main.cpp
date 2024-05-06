#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

//cd  int main()
// {
// 	try
// 	{
// 		Form a("a", 160, 140);
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	try
// 	{
// 		Form b("b", 140, 0);
// 	}
// 	catch (const std::exception& e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}

// 	Form form("Treaty", 50, 10);
// 	Bureaucrat alex("Kamala Harris", 60);
// 	Bureaucrat bob("Joe", 5);

// 	alex.signForm(form);
// 	std::cout << form << std::endl;
	
// 	bob.signForm(form);
// 	std::cout << form << std::endl;
// 	bob.signForm(form);
// }

static void cterm(void)
{
	std::cin.get();
	std::cout << "\e[1;1H\e[2J";
}

int main()
{
	std::cout << "Let's create a form with grade to sign 0" << std::endl;
	try
	{
		Form	f("EB110", 0, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception grade to sign: " << e.what() << std::endl;
	}
	cterm();
	std::cout << "\nLet's create a form with grade to execute 0" << std::endl;
	try
	{
		Form	f("EB111", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception grade to execute: " << e.what() << std::endl;
	}
	cterm();
	std::cout << "\nLet's create a form with grade to execute 151" << std::endl;
	try
	{
		Form	f("EB112", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	cterm();
	std::cout << "\nLet's create a form with grade to sign 151" << std::endl;
	try
	{
		Form	f("EB113", 151, 1);
	}
	catch (std::exception &e)
	{
		std::cout << "Exeption: " << e.what() << std::endl;
	}
	cterm();
	std::cout << "\nLet's sign a form with appropriate bureaucrat\n" << std::endl;
	try
	{
		Bureaucrat	Odin("Odin", 1);
		Form		f("EB114", 150, 150);

		std::cout << GOLD << f << RESET << std::endl;

		Odin.signForm(f);

		std::cout << GOLD << f << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	cterm();
	std::cout << std::endl;
	std::cout << "\nLet's sign a form with inappropriate bureaucrat\n" << std::endl;
	try
	{
		Bureaucrat	Thor("Thor", 10);
		Form		f("EB115", 1, 1);

		std::cout << GOLD << f << RESET << std::endl;

		Thor.signForm(f);

		std::cout << GOLD << f << RESET << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
