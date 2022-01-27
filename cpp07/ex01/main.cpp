/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:35:46 by crochu            #+#    #+#             */
/*   Updated: 2022/01/27 11:48:51 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void display_string(const char *s) {
	std::cout << s << std::endl;
}

int main(int argc, char **argv) {
	::iter(argv + 1, argc - 1, display_string);
	return 0;
}
