/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:22:10 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 23:21:05 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Ice.hpp"

Ice::Ice() { m_type = "ice", m_msg = "shoots an ice bolt at %"; }

Ice::Ice(const Ice &other) {

	static_cast< void >(other);
	m_type = "ice";
	m_msg = "shoots an ice bolt at %";
}

Ice::~Ice() { }

Ice	&Ice::operator =(const Ice &other) {
	static_cast< void >(other);
	return *this;
}
