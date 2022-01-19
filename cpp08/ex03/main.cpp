/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 01:45:26 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 03:12:20 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MindOpen.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
#include <cstring>
#include <stddef.h>

int strrncmp(const std::string s1, const std::string s2, size_t n) {
	std::string::const_reverse_iterator it1(s1.rbegin()), it2(s2.rbegin());

	while (n-- && it1 != s1.rend() && it2 != s2.rend() && *it1 == *it2)
		++it1, ++it2;
	return !!~n * (*it1 - *it2);
}

int main(int argc, const char **argv) {
	try {
		MindOpen					mo;
		UniquePtr< std::istream >	input;

		if (argc > 2) throw std::invalid_argument("invalid_argument");
		if (argc == 2) {
			if (strrncmp(argv[1], ".mindopen", 9)) throw std::invalid_argument("invalid_argument");
			if (!(input = new std::ifstream(argv[1])))
				throw MindOpen::EInvalidInput();
		} else input = new std::istream(std::cin.rdbuf());
		mo.execute(*input);
	} catch (const std::invalid_argument &e) {
		std::cerr << "Usage: " << *argv << " [file.mindopen]" << std::endl;
		return 1;
	} catch (const std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
}