/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 17:52:55 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 18:25:39 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <stdexcept>

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Trie.hpp"

#ifndef INV_LMIT
# define INV_LIMIT 4
#endif

static Trie< AMateria* >	g_materiaTrie;

static bool	initMaterias(void) {
	std::ifstream	dataFile("Materias.txt", std::ios::in);

	if (dataFile.bad())
		throw std::runtime_error("can't open Materias.txt");
	g_materiaTrie.insert("cure", new Cure);
	g_materiaTrie.insert("ice", new Ice);
	while (dataFile >> g_materiaTrie)
		continue ;
}

MateriaSource::MateriaSource() : m_inventory() {
	static bool	init = initMaterias();
	static_cast< void >(init);
}

MateriaSource::MateriaSource(const MateriaSource &other) {
	
}
