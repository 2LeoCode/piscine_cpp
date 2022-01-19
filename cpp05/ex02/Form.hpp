/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:34 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 00:59:04 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form {
	public:

	Form(std::string name = "generic", std::string target = "dummy",
		int gradeToSign = 150, int gradeToExec = 150,
		void (*action)(std::string) = NULL);
	virtual ~Form();
	const std::string	&getName(void) const;
	int					getGradeToSign(void) const;
	int					getGradeToExec(void) const;
	bool				isSigned(void) const;

	Form	&beSigned(const Bureaucrat &b);
	Form	&beExecuted(const Bureaucrat &b);

	struct FormNotSignedException : public std::exception {
		virtual const char	*what() const throw();
	};
	struct FormAlreadySignedException : public std::exception {
		virtual const char	*what() const throw ();
	};
	virtual void	__abstract__() = 0;

	protected:

	const std::string	_name;
	const std::string	_target;
	void				(*_action)(std::string);
	const int			_gradeToSign;
	const int			_gradeToExec;
	bool				_signed;
};

std::ostream	&operator<<(std::ostream &out, Form &f);

#endif
