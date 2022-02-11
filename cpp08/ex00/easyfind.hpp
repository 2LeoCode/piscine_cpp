/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:34:01 by crochu            #+#    #+#             */
/*   Updated: 2022/02/11 19:34:16 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

#define NOT_FOUND ~0

template <
	class Container
> size_t easyfind(const Container &cont, int value) {
	size_t								pos = 0;
	typename Container::const_iterator	it = cont.begin();

	while (it != cont.end()) {
		if (*it++ == value) return pos;
		++pos;
	}
	return NOT_FOUND;
}
