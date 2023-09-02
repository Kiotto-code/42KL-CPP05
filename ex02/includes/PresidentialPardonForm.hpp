/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 17:33:03 by yichan            #+#    #+#             */
/*   Updated: 2023/09/03 00:26:51 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_CLASS_H
# define PRESIDENTIAL_PARDON_FORM_CLASS_H

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm(std::string const & target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &	operator=(PresidentialPardonForm const & src);

		std::string const &	getTarget(void) const;

		static int const	gradeToSign = 25;
		static int const	gradeToExecute = 5;
		void				execute(const Bureaucrat& executor) const;

	private:
		std::string	_target;
};

#endif
