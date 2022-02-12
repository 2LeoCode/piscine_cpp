/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 03:05:34 by crochu            #+#    #+#             */
/*   Updated: 2022/02/12 16:55:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include "Random.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>

int main(void) {
	Random	rng;
	try {
		Span	sp = Span(5);

		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << "---Span 1---\n" << sp << std::endl;
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;

		Span	rd = Span(10);

		for (int i = 0; i < 10; ++i)
			rd.addNumber(rng(1, 100));
		std::cout << "---Span 2---\n" << rd << std::endl;
		std::cout << "Shortest span: " << rd.shortestSpan() << std::endl;
		std::cout << "Longest span: " << rd.longestSpan() << std::endl;
	} catch (...) {
		std::cerr << "Abnormal termination" << std::endl;
	}
	return 0;
}
