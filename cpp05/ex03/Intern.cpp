/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:28:15 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 01:14:18 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

#define I Intern

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

Form *I::makeForm(std::string type, std::string target) {
	for (unsigned i = 0; i < 3; ++i)
		if (!type.compare(formType[i])) {
			std::cout << "Intern creates " << type << std::endl;
			return (formAllocator[i](target));
		}
	std::cout << "Form " << type << " does not exist" << std::endl;
	return (NULL);
}
