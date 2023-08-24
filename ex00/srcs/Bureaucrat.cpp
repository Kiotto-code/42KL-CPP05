/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 00:20:58 by yichan            #+#    #+#             */
/*   Updated: 2023/08/24 01:24:10 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void){
	std::cout << "[Bureaucrat] default constructor being called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name) : _name(name)
{
	std::cout << "[Bureaucrat] constructor with name str being called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
	*this = other;
	std::cout << "[Bureaucrat] copy constructor with name str being called" << std::endl;
}

Bureaucrat::~Bureaucrat(void){
	std::cout << "[Bureaucrat] destructor being called" << std::endl;
};

Bureaucrat	&Bureaucrat::operator = (const Bureaucrat &other)
{
	this->_grade = other._grade;
	// this->_name = other._name;
	return (*this);
}