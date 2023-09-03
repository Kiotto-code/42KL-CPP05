/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:33:14 by yichan            #+#    #+#             */
/*   Updated: 2023/09/03 22:42:22 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_CLASS_H
# define ROBOTOMY_REQUEST_FORM_CLASS_H

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm(std::string const & target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &	operator=(RobotomyRequestForm const & src);

		std::string const &	getTarget(void) const;

		static int const	gradeToSign = 72;
		static int const	gradeToExecute = 45;
		void	execute(const Bureaucrat &executor) const;

	private:
		std::string	_target;
};

#endif
