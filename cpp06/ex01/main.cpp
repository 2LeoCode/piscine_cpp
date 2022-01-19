/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:32:03 by crochu            #+#    #+#             */
/*   Updated: 2021/11/06 16:39:06 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

#include <iostream>
#include <stdint.h>

#define RC reinterpret_cast

uintptr_t serialize(Data *data) {
	return RC< uintptr_t >(data);
}

Data *deserialize(uintptr_t addr) {
	return RC< Data* >(addr);
}

int main(void) {
	Data var = { 42 };

	std::cout << var.value << std::endl;

	uintptr_t addr = serialize(&var);
	Data *ptr = deserialize(addr);

	std::cout << ptr->value << std::endl;
	return 0;
}
