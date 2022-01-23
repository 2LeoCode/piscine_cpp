/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:38:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:56:15 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <stdexcept>

#include "Character.hpp"
#include "utils.hpp"

Character::Character() : m_name("unnamed"), m_itemCnt(0) { }

Character::~Character() {
	for (unsigned i = 0; i < m_itemCnt; ++i)
		delete m_inventory[i];
}

Character::Character(const Character &other)
:	m_name(other.m_name),
	m_itemCnt(other.m_itemCnt) {
	for (unsigned i = 0; i < m_itemCnt; ++i)
		m_inventory[i] = other.m_inventory[i]->clone();
}

Character::Character(std::string name) : m_name(name), m_itemCnt(0) { }

Character	&Character::operator =(const Character &other) {
	m_name = other.m_name;
	m_itemCnt = other.m_itemCnt;
	for (unsigned i = 0; i < m_itemCnt; ++i)
		m_inventory[i] = other.m_inventory[i]->clone();
	return *this;
}

std::string const	&Character::getName() const { return m_name; }

void				Character::equip(AMateria *m) {
	if (m && m_itemCnt < 4)
		m_inventory[m_itemCnt++] = m;
}

void				Character::unequip(int idx) {
	if (idx < 0 || idx >= static_cast< int >(m_itemCnt))
		throw std::out_of_range("Character::unequip");
	ft::copy(m_inventory + idx + 1, m_inventory + m_itemCnt--, m_inventory + idx);
}

void				Character::use(int idx, ICharacter &target) {
	if (idx < 0 || idx >= static_cast< int >(m_itemCnt))
		throw std::out_of_range("Character::use");
	m_inventory[idx]->use(target);
}
