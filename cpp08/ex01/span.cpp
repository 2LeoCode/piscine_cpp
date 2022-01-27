/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:00:28 by crochu            #+#    #+#             */
/*   Updated: 2022/01/27 14:26:16 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

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

const char *Span::ENoSpan::what() const throw () { return "Not enough numbers"; }
const char *Span::ESpanFull::what() const throw () { return "Array is full"; }
