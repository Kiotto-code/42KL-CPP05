#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class	Form
{
	private:
		std::string const	m_name;
		bool				m_signState;
		const	int			m_signGrade;
		const	int			m_executeGrade;

	public:
		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		Form(void);
		Form(const std::string &name, const int sign_grade, const int &execute_grade);
		Form(const Form &other);
		~Form(void);

		//operator_overload
		Form	&operator= (const Form &other);
		//getter
		const	std::string	&getName( void ) const;
		bool				getSign_state( void ) const;
		int			getSign_grade( void ) const;
		int			getExecute_grade( void ) const;

		void				beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what() const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
};

// std::ostream& operator<<(std::ostream &out, const Form &form);
std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif
