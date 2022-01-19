/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:00:28 by crochu            #+#    #+#             */
/*   Updated: 2021/11/08 03:18:03 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

#define diff(a, b) ((a) < (b) ? (b) - (a) : (a) - (b))

S::Constructor(unsigned N) : _size(0), _cap(N), _ptr(new int[N]) { }

S::Destructor() {
	delete[] _ptr;
}

void S::addNumber(int n) {
	if (_size == _cap) throw ESpanFull();
	_ptr[_size++] = n;
}

unsigned S::shortestSpan(void) const {
	if (_size < 2) throw ENoSpan();
	unsigned shortest_span = ~0;

	for (unsigned i = 1; i < _size; ++i) {
		unsigned current_span = diff(_ptr[i], _ptr[i - 1]);
		if (current_span < shortest_span) shortest_span = current_span;
	}
	return (shortest_span);
}

unsigned S::longestSpan(void) const {
	if (_size < 2) throw ENoSpan();
	unsigned longest_span = 0;

	for (unsigned i = 1; i < _size; ++i) {
		unsigned current_span = diff(_ptr[i], _ptr[i - 1]);
		if (current_span > longest_span) longest_span = current_span;
	}
	return (longest_span);
}

const char *S::ENoSpan::what() const throw () { return "Not enough numbers"; }
const char *S::ESpanFull::what() const throw () { return "Array is full"; }
