#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
// #include <iomanip>
#include <fstream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;
class	AForm
{
	private:
		std::string const	m_name;
		bool				m_signState;
		const	int			m_signGrade;
		const	int			m_executeGrade;

	public:
		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		AForm(void);
		AForm(const std::string &name, const int sign_grade, const int execute_grade);
		AForm(const AForm &other);
		virtual ~AForm(void);

		//operator_overload
		AForm	&operator= (const AForm &other);
		//getter
		const	std::string	&getName( void ) const;
		bool				getSign_state( void ) const;
		int			getSign_grade( void ) const;
		int			getExecute_grade( void ) const;

		void			beSigned(const Bureaucrat &bureaucrat);
		void			checkExecute(Bureaucrat const &bureaucrat) const;
		virtual void	execute(Bureaucrat const &bureaucrat) const = 0;

		class GradeTooHighException: public std::exception{
			public:
				virtual const char* what(void) const throw();
		};
		class GradeTooLowException: public std::exception{
			public:
				virtual const char* what(void) const throw();
		};
		class AlreadySignedException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
		class InvalidFormException : public std::exception {
			public:
				virtual const char *	what(void) const throw();
		};
};

// std::ostream& operator<<(std::ostream &out, const AForm &AForm);
std::ostream	&operator<<(std::ostream &out, const AForm &AForm);

template <typename T>
std::string		getDataType(const T &object)
{
	std::string denumbered;
	std::string type = typeid(object).name();

	size_t pos = type.find_first_not_of("0123456789");
    if (pos != std::string::npos) {
        // Return the substring before the first digit
        denumbered = std::string(type.substr(pos));
		return denumbered;
    }
    // If no digit found, return the original string
    return "";
}

#endif
