/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fun.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:21:03 by crochu            #+#    #+#             */
/*   Updated: 2021/11/07 15:39:25 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft {
	template <typename T>
	void swap(T &a ,T &b) {
		const T tmp = a;
	
		a = b;
		b = tmp;
	}

	template <typename T>
	T min(T a, T b) {
		if (b < a) return b;
		return a;
	}

	template <typename T>
	T max(T a, T b) {
		if (b > a) return b;
		return a;
	}
}