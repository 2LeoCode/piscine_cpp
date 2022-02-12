/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:57:39 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 16:55:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>

class Span {
	public:
		Span(unsigned N);
		Span(const Span &other);
		~Span();

		Span	&operator =(const Span &other);
		void addNumber(int n);

		unsigned shortestSpan(void) const;
		unsigned longestSpan(void) const;

		const int	*begin(void) const;
		const int	*end(void) const;

		struct ESpanFull : public std::exception {
			const char *what() const throw ();
		};
		struct ENoSpan : public std::exception {
			const char *what() const throw ();
		};

	private:
		unsigned	m_size;
		unsigned	m_cap;
		int			*m_data;
};

std::ostream &operator <<(std::ostream &, const Span &);
