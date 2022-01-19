/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:54 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/02 21:54:11 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

#define B Bureaucrat

B::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade % 150) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
}

B::~Bureaucrat() { }

B::Bureaucrat(const Bureaucrat &other) : _name(other._name),
_grade(other._grade) { }

const std::string &B::getName(void) const {
	return _name;
}

int B::getGrade(void) const {
	return _grade;
}

void B::upgrade(void) {
	if (_grade - 1 < 1) throw (B::GradeTooHighException());
	--_grade;
}

void B::downgrade(void) {
	if (_grade + 1 > 150) throw (B::GradeTooLowException());
	++_grade;
}

const char *B::GradeTooHighException::what(void) const throw () {
	return "Grade too high";
}

const char *B::GradeTooLowException::what(void) const throw () {
	return "Grade too low";
}

void B::signForm(Form &f) const {
	try {
		f.beSigned(*this);
		std::cout << _name << " signs " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " cannot sign " << f.getName() << " because " <<
		e.what() << std::endl;
	}
}

void B::executeForm(Form &f) const {
	try {
		f.beExecuted(*this);
		std::cout << _name << " executes " << f.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " cannot execute " << f.getName() << " because " <<
		e.what() << std::endl;
	}
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}
