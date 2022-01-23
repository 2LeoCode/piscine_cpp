/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Materia.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 18:43:27 by lsuardi           #+#    #+#             */
/*   Updated: 2022/01/23 23:38:30 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Materia.hpp"

Materia::Materia() : m_msg("???") {
	m_type = "unknown";
}

Materia::Materia(const Materia &other)
:	m_msg(other.m_msg)
{ m_type = other.m_type; }

Materia::Materia(std::string type, std::string msg) : m_msg(msg) {
	m_type = type;
}

Materia::~Materia() { }

Materia	&Materia::operator =(const Materia &other) {
	m_type = other.m_type;
	m_msg = other.m_msg;
	return *this;
}

AMateria	*Materia::clone(void) const { return new Materia(*this); }

void	Materia::use(ICharacter &target) {
	std::string	output("* " + m_type + ' ' + m_msg + " *");

	output.replace(output.find_first_of('%'), 1, target.getName());
	std::cout << output << std::endl;
}

std::istream	&operator >>(std::istream &in, Materia &m) {
	std::string	type, msg;
	char		c;

	if (
		std::getline(in, type, ' ')
		&& in >> c
		&& c == '"' && std::getline(in, msg, '"')
	) m = Materia(type, msg);
	else
		in.setstate(std::ios::failbit);
	return in;
}
