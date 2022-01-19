/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:00:02 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 12:23:21 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

#include <iostream>

#define PPF PresidentialPardonForm

void presidentialPardon(std::string target) {
	std::cout << target << " has been pardonned by Zafod Beeblebrox" <<
	std::endl;
}

PPF::PresidentialPardonForm(std::string target) :
Form("pardon", target, 25, 5, presidentialPardon) { }

void PPF::_() { }
