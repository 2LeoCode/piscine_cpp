/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:31 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 00:07:40 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

#include <iostream>

#define F Form

F::Form(std::string name, std::string target, int gradeToSign, int gradeToExec,
	void (*action)(std::string)) : _name(name), _target(target),
_action(action), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw Bureaucrat::GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw Bureaucrat::GradeTooLowException();
}

F::~Form() { }

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
	if (b.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_signed = true;
	return *this;
}

Form &F::beExecuted(const Bureaucrat &b) {
	if (!_signed) throw FormNotSignedException();
	if (b.getGrade() > _gradeToExec)
		throw Bureaucrat::GradeTooLowException();
	if (_action)
		_action(_target);
	else
		std::cout << _name << " has been executed on " << _target << std::endl;
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
