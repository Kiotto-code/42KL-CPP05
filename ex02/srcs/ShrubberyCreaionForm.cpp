/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreaionForm.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 23:35:07 by yichan            #+#    #+#             */
/*   Updated: 2023/09/03 02:18:52 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target("")
{
	std::cout << "[ShrubberyCreationForm] default constructor was being called " << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) 
	: AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target(target) {
	std::cout << "[ShrubberyCreationForm] default constructor w string was being called " << std::endl;
	}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) 
	: AForm("ShrubberyCreationForm", gradeToSign, gradeToExecute), _target(src.getTarget()) {
	std::cout << "[ShrubberyCreationForm] copy constructor was being called " << std::endl;
	}

const std::string&		ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
};

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream file;

	this->checkExecute(executor);
	file.open(this->_target+"_shrubbery");

	file << "MMMMMMMMWWWWWWWWWWXK0OkkkkO0XNWMMMMMMMMM" << std::endl;
	file << "MMMMMWXKOOOkkxdO0kxoollooddddxxkOXWMMMMM" << std::endl;
	file << "MMMWN0dodxxdollodxxxxxxxxxxxxxdoloxXWMMM" << std::endl;
	file << "MMWKkddddddlodxxxxxxxxdoooddxddddl;cOWMM" << std::endl;
	file << "MW0xdxxxdlccldxxxxxddoc;;::codolllc:ckWM" << std::endl;
	file << "N0xxxxxxoc::;;cclolc;;'...',;;;coodocoXM" << std::endl;
	file << "Xddxxxdlc;,'...'',,..........,coxxxxddOW" << std::endl;
	file << "WKxoolc:;''''...........''.'.,lddxxxdooO" << std::endl;
	file << "MMN00x:'''',;,'.......','..'',:clllcc:oX" << std::endl;
	file << "MMMMMWXOkdd0XKkc;;,;clccdd;.'',lol:lxOXM" << std::endl;
	file << "MMMMMMMMMMMMMMMWX0o;:;lKWWXO00KNWNNNWWMM" << std::endl;
	file << "MMMMMMMMMMMMMMMMMWk'.;0WMMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMMMMWk,.cKMMMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMMMMNd'.cKMMMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMMMMXo'.:KMMMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMMMMNd,';OMMMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMMMWXl,,;xWMMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMMNKd,',,cONMMMMMMMMMMMMMMM" << std::endl;
	file << "MMMMMMMMMMMMMMWXkdoxkkxkXMMMMMMMMMMMMMMM" << std::endl;
	file.close();
}