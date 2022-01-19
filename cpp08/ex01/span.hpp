/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:57:39 by crochu            #+#    #+#             */
/*   Updated: 2021/11/08 03:17:09 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>

#define S Span
#define Constructor S
#define Destructor ~S

class Span {
	public:
		Constructor(unsigned N);
		Destructor();

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
		unsigned	_size;
		unsigned	_cap;
		int			*_ptr;
};
