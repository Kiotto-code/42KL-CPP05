#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "AForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

// template <typename T>
class	Intern
{
	private:
		typedef struct	s_pair
		{
			std::string	type;
			AForm		*form;
		}				t_pair;
	public:
		Intern( void );
		~Intern( void );

		AForm* makeForm(std::string const &formName, std::string const &target) const;

		class InvalidFormNameException: public std::exception{
			public:
				virtual const char* what(void) const throw();
		};
		/*My testing on making pair lists using structPair*/

};



#endif