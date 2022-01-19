/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 03:34:11 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 00:20:21 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main(void) {
	std::string	inputLine;
	PhoneBook	book;

	while (true) {
		std::cout << "$ ";
		std::getline(std::cin, inputLine);
		book.execute(inputLine);
	}
	return 0;
}