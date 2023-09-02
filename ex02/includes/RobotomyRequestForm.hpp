/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:33:14 by yichan            #+#    #+#             */
/*   Updated: 2023/08/31 17:33:19 by yichan           ###   ########.fr       */
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

		void	beExecuted(void) const;

		static int const	gradeToSign = 72;
		static int const	gradeToExecute = 45;

	private:
		std::string	_target;
};

#endif
