/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:34 by crochu            #+#    #+#             */
/*   Updated: 2022/01/25 23:45:09 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Bureaucrat.hpp"
#include <string>

class Bureaucrat;

class Form {
	public:
		Form();
		~Form();

		Form(const Form&);

		Form(std::string);
		Form(std::string, int);

		Form	&operator =(const Form&);

		const std::string	&getName(void) const;
		int					gradeToSign(void) const;
		bool				isSigned(void) const;

		Form	&beSigned(const Bureaucrat&);

		struct EAlreadySigned : public std::exception {
			virtual const char	*what() const throw ();
		};


	private:
		const std::string	m_name;
		const int			m_gradeToSign;
		bool				m_signed;
};

std::ostream	&operator <<(std::ostream &, Form &);
