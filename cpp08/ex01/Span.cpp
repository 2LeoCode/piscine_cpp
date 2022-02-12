/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:00:28 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 16:57:46 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define diff(a, b) ((a) < (b) ? (b) - (a) : (a) - (b))

Span::Span(unsigned N) : m_size(0), m_cap(N), m_data(new int[N]) { }

Span::~Span() {
	delete[] m_data;
}

void Span::addNumber(int n) {
	if (m_size == m_cap) throw ESpanFull();
	m_data[m_size++] = n;
}

unsigned Span::shortestSpan(void) const {
	if (m_size < 2) throw ENoSpan();
	unsigned shortest_span = ~0;

	for (unsigned i = 1; i < m_size; ++i) {
		unsigned current_span = diff(m_data[i], m_data[i - 1]);
		if (current_span < shortest_span) shortest_span = current_span;
	}
	return (shortest_span);
}

unsigned Span::longestSpan(void) const {
	if (m_size < 2) throw ENoSpan();
	unsigned longest_span = 0;

	for (unsigned i = 1; i < m_size; ++i) {
		unsigned current_span = diff(m_data[i], m_data[i - 1]);
		if (current_span > longest_span) longest_span = current_span;
	}
	return (longest_span);
}

const int	*Span::begin(void) const { return m_data; }
const int	*Span::end(void) const { return m_data + m_size; }

const char *Span::ENoSpan::what() const throw () { return "Not enough numbers"; }
const char *Span::ESpanFull::what() const throw () { return "Array is full"; }

std::ostream &operator <<(std::ostream &out, const Span &sp) {
	for (const int *ptr = sp.begin(); ptr != sp.end(); ++ptr)
		out << '[' << *ptr << ']';
	return out;
}
