/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:57:51 by crochu            #+#    #+#             */
/*   Updated: 2022/01/25 23:28:06 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form {
	public:
		PresidentialPardonForm(std::string target = "dummy");


	private:
		void	m__abstract__() const;
};
