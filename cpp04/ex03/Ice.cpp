/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:22:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:33:36 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"

Ice::Ice() { m_type = "ice"; }

Ice::~Ice() { }

AMateria	*Ice::clone(void) const { return new Ice; }

void	Ice::use(ICharacter &target) {
	std::cout <<
		"* shoots an ice bolt at " << target.getName() << " *" <<
	std::endl;
}
