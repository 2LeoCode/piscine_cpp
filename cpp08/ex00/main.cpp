/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 02:33:13 by crochu            #+#    #+#             */
/*   Updated: 2022/02/11 20:13:17 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include <vector>
#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>

template <
	class Container
> void	test_easyfind(const Container &cont, int value) {
	size_t	pos;

	std::cout << "Container type: " << typeid(Container).name() << '\n';
	std::cout << "Value: " << value << '\n';
	if (!~(pos = easyfind(cont, value)))
		std::cout << "Not found";
	else std::cout << "Found: " << pos;
	std::cout << '\n' << std::endl;
}

int main(void) {
	std::vector< int >	v(10, 5);
	std::list< int >	l(10, 5);

	v[0] = 1;
	v[5] = 0;
	*++(++(++l.begin())) = 42;
	*l.rbegin() = 0;
	test_easyfind(v, 0);
	test_easyfind(v, 1);
	test_easyfind(v, 10);
	test_easyfind(v, 42);
	test_easyfind(l, 0);
	test_easyfind(l, 1);
	test_easyfind(l, 10);
	test_easyfind(l, 42);
	return 0;
}
