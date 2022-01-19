/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 20:25:48 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/03 00:58:53 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "Form.hpp"
# include <string>

class Form;

class Bureaucrat {
	public:

	Bureaucrat(std::string name = "unnamed", int grade = 150);
	~Bureaucrat();

	Bureaucrat(const Bureaucrat &other);


	const std::string	&getName(void) const;
	int					getGrade(void) const;

	void				upgrade(void);
	void				downgrade(void);
	void				signForm(Form &f) const;
	void				executeForm(Form &f) const;

	struct GradeTooHighException : public std::exception {
		virtual const char	*what() const throw();
	};

	struct GradeTooLowException : public std::exception {
		virtual const char	*what() const throw();
	};


	private:

	const std::string	_name;
	int					_grade;
};

std::ostream	&operator<<(std::ostream &out, Bureaucrat &b);

#endif //BUREAUCRAT_HPP
