/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:33:13 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 02:22:37 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>

int main(void) {
	std::vector< int > v(10, 5);
	size_t foundIndex;

	v[5] = 0;
	std::cout << "Searching for 5..." << std::endl;
	if (!~(foundIndex = easyfind(v, 5)))
		std::cout << "Not found" << std::endl;
	else std::cout << "Found 5 at pos " << foundIndex << std::endl;
	std::cout << "Searching for 0..." << std::endl;
	if (!~(foundIndex = easyfind(v, 0)))
		std::cout << "Not found" << std::endl;
	else std::cout << "Found 0 at pos " << foundIndex << std::endl;
	std::cout << "Searching for 42..." << std::endl;
	if (!~(foundIndex = easyfind(v, 42)))
		std::cout << "Not found" << std::endl;
	else std::cout << "Found 42 at pos " << foundIndex << std::endl;
	return 0;
}
