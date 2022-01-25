/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:54 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 23:44:45 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat()
:	m_name("Unnamed Bureaucrat"),
	m_grade(150)
{ }

Bureaucrat::~Bureaucrat() { }

Bureaucrat::Bureaucrat(const Bureaucrat &other)
:	m_name(other.m_name),
	m_grade(other.m_grade)
{ }

Bureaucrat::Bureaucrat(std::string name)
:	m_name(name),
	m_grade(150)
{ }

Bureaucrat::Bureaucrat(std::string name, int grade)
:	m_name(name) {
	if (grade < 1) {
		m_grade = 1;
		throw Bureaucrat::EGradeTooHigh();
	}
	else if (grade > 150) {
		m_grade = 150;
		throw Bureaucrat::EGradeTooLow();
	}
	else m_grade = grade;
}

Bureaucrat	&Bureaucrat::operator =(const Bureaucrat &other) {
	m_grade = other.m_grade;
	return *this;
}

const std::string	&Bureaucrat::getName(void) const { return m_name; }

int	Bureaucrat::getGrade(void) const { return m_grade; }

void	Bureaucrat::upgrade(void) {
	if (m_grade - 1 < 1) throw Bureaucrat::EGradeTooHigh();
	--m_grade;
}

void	Bureaucrat::downgrade(void) {
	if (m_grade + 1 > 150) throw Bureaucrat::EGradeTooLow();
	++m_grade;
}

const char	*Bureaucrat::EGradeTooHigh::what(void) const throw () {
	return "Grade too high";
}

const char	*Bureaucrat::EGradeTooLow::what(void) const throw () {
	return "Grade too low";
}

void	Bureaucrat::signForm(Form &f) const {
	try {
		f.beSigned(*this);
	} catch (std::exception &e) {
		std::cout << m_name << " cannot sign " << f.getName() << " because " <<
		e.what() << std::endl;
	}
}

std::ostream	&operator <<(std::ostream &out, const Bureaucrat &b) {
	return out << b.getName() << ", bureaucrat grade " << b.getGrade();
}
