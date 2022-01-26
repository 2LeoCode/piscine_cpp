/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:32:03 by crochu            #+#    #+#             */
/*   Updated: 2022/01/26 16:11:27 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>
#include <stdint.h>

uintptr_t serialize(Data *data) {
	return reinterpret_cast< uintptr_t >(data);
}

Data *deserialize(uintptr_t addr) {
	return reinterpret_cast< Data* >(addr);
}

int main(void) {
	Data var = { 42 };

	std::cout << var.value << std::endl;

	uintptr_t addr = serialize(&var);
	Data *ptr = deserialize(addr);

	std::cout << ptr->value << std::endl;
	return 0;
}
