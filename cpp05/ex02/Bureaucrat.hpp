/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/25 22:59:09 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Form.hpp"
# include <string>

class Form;

class Bureaucrat {
	public:
		Bureaucrat();
		~Bureaucrat();

		Bureaucrat(const Bureaucrat&);

		Bureaucrat(std::string);
		Bureaucrat(std::string, int);

		Bureaucrat	&operator =(const Bureaucrat&);

		const std::string	&getName(void) const;
		int					getGrade(void) const;

		void				upgrade(void);
		void				downgrade(void);
		void				signForm(Form&) const;
		void				executeForm(const Form&) const;

		struct EGradeTooHigh : public std::exception {
			virtual const char	*what() const throw();
		};

		struct EGradeTooLow : public std::exception {
			virtual const char	*what() const throw();
		};


	private:
		const std::string	m_name;
		int					m_grade;
};

std::ostream	&operator <<(std::ostream&, const Bureaucrat&);
