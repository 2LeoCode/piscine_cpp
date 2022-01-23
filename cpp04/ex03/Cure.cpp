/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:27:00 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 23:38:52 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Cure.hpp"

Cure::Cure() { m_type = "cure", m_msg = "heals %'s wounds"; }

Cure::Cure(const Cure &other) {
	static_cast< void >(other);
	m_type = "cure";
	m_msg = "heals %'s wounds";
}

Cure::~Cure() { }

Cure	&Cure::operator =(const Cure &other) {
	static_cast< void >(other);
	return *this;
}
