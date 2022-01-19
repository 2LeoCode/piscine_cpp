/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:31 by crochu            #+#    #+#             */
/*   Updated: 2021/11/02 23:16:13 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

#define F Form

F::Form() : _name("Unnamed form"), _gradeToSign(150), _gradeToExec(150),
_signed(false) { }

F::~Form() { }

F::Form(std::string name) : _name(name), _gradeToSign(150), _gradeToExec(150),
_signed(false) { }

F::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name),
_gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _signed(false) {
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw (Bureaucrat::GradeTooHighException());
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw (Bureaucrat::GradeTooLowException());
}

const std::string &F::getName(void) const {
	return _name;
}

int F::getGradeToSign(void) const {
	return _gradeToSign;
}

int F::getGradeToExec(void) const {
	return _gradeToExec;
}

bool F::isSigned(void) const {
	return _signed;
}

Form &F::beSigned(const Bureaucrat &b) {
	if (_signed) throw FormAlreadySignedException();
	if (b.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
	return *this;
}

Form &F::beExecuted(const Bureaucrat &b) {
	if (!_signed) throw FormNotSignedException();
	if (b.getGrade() > _gradeToExec)
		throw Bureaucrat::GradeTooLowException();
	std::cout << "Executed form " << _name << std::endl;
	return *this;
}

const char *F::FormNotSignedException::what() const throw () {
	return "Form not signed";
}

const char *F::FormAlreadySignedException::what() const throw () {
	return "Form already signed";
}

std::ostream &operator<<(std::ostream &out, Form &f) {
	out << f.getName() << " form grade to sign " << f.getGradeToSign() <<
	", grade to execute " << f.getGradeToExec() << '.' << std::endl <<
	"Signed: " << (f.isSigned() ? "true" : "false") << std::endl;
	return out;
}
