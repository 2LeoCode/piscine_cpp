/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:40:10 by crochu            #+#    #+#             */
/*   Updated: 2021/11/08 01:48:20 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#include <iostream>

int main(void) {
	try {
		Array< int > a, b(42);

		for (unsigned i = 0; i < b.size(); ++i) {
			b[i] = 42;
		}
		std::cout << "b: ";
		b.print();
		a = b;
		std::cout << "a = b" << std::endl;
		std::cout << "a: ";
		a.print();
		for (unsigned i = 0; i < a.size(); ++i) {
			a[i] = 21;
		}
		std::cout << "a: ";
		a.print();
		std::cout << "b: ";
		b.print();
		try {
			std::cout << "a[41]: " << a[41] << std::endl;
			std::cout << "a[42]: " << a[42] << std::endl;
		} catch (const std::exception &e) {
			std::cerr << "exception caught: " << e.what() << std::endl;
		}
	} catch (...) {
		std::cerr << "Abnormal termination" << std::endl;
		return 1;
	}
	return 0;
}
