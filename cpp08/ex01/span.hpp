/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:57:39 by crochu            #+#    #+#             */
/*   Updated: 2022/01/27 14:24:46 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

class Span {
	public:
		Span(unsigned N);
		Span(const Span &other);
		~Span();

		Span	&operator =(const Span &other);
		void addNumber(int n);

		unsigned shortestSpan(void) const;
		unsigned longestSpan(void) const;

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
