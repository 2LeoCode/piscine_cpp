/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:28:15 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 00:03:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

static Form *newShrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

static Form *newRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

static Form *newPresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

static const std::string formType[3] = {
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

static Form *(*const formAllocator[3])(std::string) = {
	newShrubberyCreationForm,
	newRobotomyRequestForm,
	newPresidentialPardonForm
};

Intern::Intern() { }

Intern::Intern(const Intern &other) { static_cast< void >(other); }

Intern::~Intern() { }

Intern	&Intern::operator =(const Intern &other) {
	static_cast< void >(other);
	return *this;
}

Form *Intern::makeForm(std::string type, std::string target) {
	for (unsigned i = 0; i < 3; ++i)
		if (type == formType[i]) {
			std::cout << "Intern creates " << type << std::endl;
			return formAllocator[i](target);
		}
	throw EDoesNotExist();
	return (NULL);
}

const char	*Intern::EDoesNotExist::what(void) const throw () {
	return "Form does not exist";
}
