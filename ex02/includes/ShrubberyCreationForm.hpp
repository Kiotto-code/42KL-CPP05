/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:33:23 by yichan            #+#    #+#             */
/*   Updated: 2023/09/03 00:28:13 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERY_CREATION_FORM_CLASS_H
# define SHRUBBERY_CREATION_FORM_CLASS_H

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm(std::string const & target);
		~ShrubberyCreationForm(void);

		ShrubberyCreationForm &	operator=(ShrubberyCreationForm const & src);

		std::string const &	getTarget(void) const;
		
		static int const	gradeToSign = 145;
		static int const	gradeToExecute = 137;
		void	execute(const Bureaucrat &executor) const;

	private:
		std::string					_target;
		static std::string const	_shrubbery;
		static std::string const	_shrubberyAlt;
};

#endif
