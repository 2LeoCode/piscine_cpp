/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:35:46 by crochu            #+#    #+#             */
/*   Updated: 2021/11/07 15:38:50 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

void display_string(const char *s) {
	std::cout << s << std::endl;
}

int main(int argc, char **argv) {
	ft::iter(argv + 1, argc - 1, display_string);
	return 0;
}
