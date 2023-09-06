# include "Intern.hpp"

Intern::Intern ( void )
{
	std::cout << "[Intern] constructor was being called" << std::endl;
}

Intern::~Intern ( void )
{
	std::cout << "[Intern] detsructor was being called " << std::endl;
}

// template <typename T1, typename T2>
// struct Pair{
// 	T1	formName;
// 	T2	target;
// 	Pair(const )
// }

const char* Intern::InvalidFormNameException::what(void) const throw()
{
	return ("FormName Given Was Not In the Record!");
}

// static AForm *	createPresidentialPardonForm(std::string const & target)
// {
// 	return (new PresidentialPardonForm(target));
// }

// static AForm *	createRobotomyRequestForm(std::string const & target)
// {
// 	return (new RobotomyRequestForm(target));
// }

// static AForm *	createShrubberyCreationForm(std::string const & target)
// {
// 	return (new ShrubberyCreationForm(target));
// }


// AForm*	Intern::makeForm(std::string const &formName, std::string const &target)
// {
// 	int i = 0;
// 	AForm	(fcnPtr[3]) = {
// 			// &PresidentialPardonForm(target),
// 			// &RobotomyRequestForm(target),
// 			// &ShrubberyCreaionForm(target),
// 			&createPresidentialPardonForm,
// 			&createRobotomyRequestForm,
// 			&createShrubberyCreationForm
// 	};
// 	static std::string arr[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreaionForm"};
// 	for (i = 0; i < 3; i++)
// 	{
// 		if (arr[i] == formName)
// 			break ;
// 	}
// 	AForm * temp = (fcnPtr[i])(target);
// 	if (i < 3)
// 		return temp;
// 	else
// 		throw Intern::InvalidFormNameException();
// }

AForm	*Intern::makeForm(const std::string& formName, const std::string& target) const
{
	AForm	*Result;
	int		i;

	t_pair	data[] = 
	{
		{ "presidential pardon", new PresidentialPardonForm(target) },
		{ "robotomy request", new RobotomyRequestForm(target) },
		{ "shrubbery creation", new ShrubberyCreationForm(target) },
		{ "", NULL}
	};

	Result = NULL;
	for (i = 0; data[i].form != NULL; i++)
	{
		if (data[i].type == formName)
			Result = data[i].form;
		else
			delete data[i].form;
	}

	if (Result == NULL || i > 4)
	{
		throw Intern::InvalidFormNameException();
	}
	else
		std::cout << "Intern creates " << formName << std::endl;
	return Result;
}