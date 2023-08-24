/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 19:04:05 by yichan            #+#    #+#             */
/*   Updated: 2023/08/24 16:58:48 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Color.hpp"
# include "Grade.hpp"

class Bureaucrat
{
	private:
		const std::string	_name;
		Grade				_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string name);
		Bureaucrat(const Bureaucrat &other);
		~Bureaucrat(void);
		
		// GradeTooHighException();
		//getter
		const std::string	getName(void);
		constGrade			getGrade(void);

		//operator overload//
		Bureaucrat &operator = (const Bureaucrat &other);
		
};

std::ostream &operator << (std::ostream &os , const Bureaucrat &other);

#endif

// #ifndef BUREAUCRAT_HPP
// # define BUREAUCRAT_HPP

// # include "Grade.hpp"

// class Bureaucrat
// {
// 	private:
// 		const std::string	name;
// 		Grade				grade;

// 	public:
// 		/* Constructor && destructor */
// 		Bureaucrat(const std::string &name, const int grade);
// 		Bureaucrat(const Bureaucrat &ref);
// 		~Bureaucrat(void);

// 		/* OperatorOverload */
// 		Bureaucrat	&operator=(const Bureaucrat &ref);

// 		/* Getters */
// 		const std::string	&getName(void) const;
// 		const Grade			&getGrade(void) const;

// 		/* MemberFunctions: Grade */
// 		void	promote(const unsigned int grade);
// 		void	demote(const unsigned int grade);
// };

// std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bureaucrat);

// #endif