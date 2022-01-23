/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:52:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 23:23:51 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <stdexcept>

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Trie.hpp"
#include "utils.hpp"

static Trie< AMateria >	g_materiaTrie;

static bool	initMaterias(void) {
	std::ifstream	dataFile("Materias.txt", std::ios::in);
	Materia			tmp;

	if (dataFile.bad())
		throw std::runtime_error("can't open Materias.txt");
	while (dataFile >> tmp)
		g_materiaTrie.insert(tmp.getType().c_str(), new Materia(tmp));
	return true;
}

MateriaSource::MateriaSource() {
	static bool	init = initMaterias();

	ft::fill(m_occupied, m_occupied + INV_LIMIT, false);
	static_cast< void >(init);
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	for (std::size_t i = 0; i < INV_LIMIT; ++i)
		if (other.m_occupied[i]) {
			m_inventory[i] = other.m_inventory[i]->clone();
			m_occupied[i] = true;
		}
}

MateriaSource::~MateriaSource() { }

MateriaSource	&MateriaSource::operator =(const MateriaSource &other) {
	for (std::size_t i = 0; i < INV_LIMIT; ++i)
		if (other.m_occupied[i]) {
			m_inventory[i] = other.m_inventory[i]->clone();
			m_occupied[i] = true;
		}
	return *this;
}

void	MateriaSource::learnMateria(AMateria *mat) {
	for (int i = 0; i < INV_LIMIT; ++i)
		if (!m_occupied[i]) {
			m_inventory[i] = mat;
			m_occupied[i] = true;
			return ;
		}
	throw EInventoryFull();
}

void	MateriaSource::unlearnMateria(int slot) {
	if (slot >= INV_LIMIT)
		throw std::out_of_range("MateriaSource::unlearnMateria");
	m_occupied[slot] = false;
}

AMateria	*MateriaSource::createMateria(const std::string &type) {
	const AMateria	*found = g_materiaTrie.search(type.c_str());

	if (found)
		return new Materia(*dynamic_cast< const Materia* >(found));
	if (type == "cure") return new Cure;
	else if (type == "ice") return new Ice;
	return new Materia;
}

const char	*MateriaSource::EInventoryFull::what(void) const throw () {
	return "MateriaSource inventory is full";
}
