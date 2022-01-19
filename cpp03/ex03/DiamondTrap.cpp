/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:53:31 by Leo Suardi        #+#    #+#             */
/*   Updated: 2021/11/08 02:12:47 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

#include <iostream>

#define M(memberName) DiamondTrap::memberName

M(DiamondTrap)() {
	_name = ClapTrap::_name;
	ClapTrap::_name += "_clap_name";
	ClapTrap::_type = "DiamondTrap";
	ClapTrap::_ep = ScavTrap::_ep;
	announceBegin();
}

M(~DiamondTrap)() { }

M(DiamondTrap)(std::string name) : ClapTrap(name), ScavTrap(name),
	FragTrap(name) {
	_name = ClapTrap::_name;
	ClapTrap::_name += "_clap_name";
	ClapTrap::_type = "DiamondTrap";
	ClapTrap::_ep = 50;
	announceBegin();
}

std::string	M(getName)(void) const {
	return (_name);
}

void	M(whoAmI)(void) const {
	std::cout << _name << ", " << ClapTrap::_name << std::endl;
}
