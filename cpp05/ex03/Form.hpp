/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:21:34 by crochu            #+#    #+#             */
/*   Updated: 2022/01/25 23:20:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Bureaucrat;

class Form {
	public:
		Form();
		Form(std::string, std::string, int, int, void (*)(std::string));
		Form(const Form &other);
		virtual ~Form();

		Form	&operator =(const Form&);

		const std::string	&getName(void) const;
		int					gradeToSign(void) const;
		int					gradeToExec(void) const;
		bool				isSigned(void) const;

		Form		&beSigned(const Bureaucrat&);
		const Form	&execute(const Bureaucrat&) const;

		struct ENotSigned : public std::exception {
			virtual const char	*what() const throw();
		};
		struct EAlreadySigned : public std::exception {
			virtual const char	*what() const throw ();
		};


	protected:
		virtual void		m__abstract__(void) const = 0;


	private:
		const std::string	m_name, m_target;
		const int			m_gradeToSign, m_gradeToExec;
		void				(*m_action)(std::string);
		bool				m_signed;
};

std::ostream	&operator<<(std::ostream &out, Form &f);

#endif
