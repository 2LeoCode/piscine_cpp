/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:48:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:50:16 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft {
	template < class InputIt, class OutputIt >
	OutputIt	copy(InputIt first, InputIt last, OutputIt d_first) {
		while (first != last)
			*d_first++ = *first++;
		return d_first;
	}
}
