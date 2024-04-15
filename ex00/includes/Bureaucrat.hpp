/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:04:05 by yichan            #+#    #+#             */
/*   Updated: 2023/08/31 15:04:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
// # include <exception>
# include "Color.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		
		// GradeTooHighException();
		//getter
		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void				incrementGrade(void);
		void				decrementGrade(void);
		void				incrementGrade(int);
		void				decrementGrade(int);

		static int const	highestGrade = 1;
		static int const	lowestGrade = 150;

		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		//operator overload//
		Bureaucrat &operator = (const Bureaucrat &other);
		
};

std::ostream &operator << (std::ostream &os , const Bureaucrat &other);

#endif
