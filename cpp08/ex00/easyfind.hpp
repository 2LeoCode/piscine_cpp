/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:34:01 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 02:21:24 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

#define NOT_FOUND ~0

template < typename T >
size_t easyfind(T intContainer, int value) {
	for (typename T::iterator it = intContainer.begin();
	it != intContainer.end(); ++it)
		if (*it == value) return it - intContainer.begin();
	return NOT_FOUND;
}
