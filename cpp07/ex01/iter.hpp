/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:32:34 by crochu            #+#    #+#             */
/*   Updated: 2021/11/07 15:38:33 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <
		typename value_type,
		typename size_type,
		typename fun_type
	>
	void iter(value_type *arr, size_type size, fun_type function) {
		while (size--) function(arr[size]);
	}
}
