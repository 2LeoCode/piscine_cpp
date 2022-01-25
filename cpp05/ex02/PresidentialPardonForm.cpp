/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:00:02 by crochu            #+#    #+#             */
/*   Updated: 2022/01/25 23:29:22 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

void doPresidentialPardon(std::string target) {
	std::cout << target << " has been pardonned by Zafod Beeblebrox" <<
	std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:	Form("pardon", target, 25, 5, doPresidentialPardon)
{ }

void PresidentialPardonForm::m__abstract__(void) const { }
