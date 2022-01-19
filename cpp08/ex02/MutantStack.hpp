/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 23:51:05 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 00:41:59 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <stack>
#include <deque>

#define MS MutantStack
#define Constructor MS
#define Destructor ~MS

template <
	typename T,
	class Container = std::deque< T >
> class MutantStack : public std::stack< T, Container > {
	public:
		typedef std::stack< T, Container > stack_type;
		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;
		typedef typename Container::reverse_iterator reverse_iterator;
		typedef typename Container::const_reverse_iterator
			const_reverse_iterator;

		iterator begin(void) { return stack_type::c.begin(); }
		iterator end(void) { return stack_type::c.end(); }
		reverse_iterator rbegin(void) { return stack_type::c.rbegin(); }
		reverse_iterator rend(void) { return stack_type::c.rend(); }
};
