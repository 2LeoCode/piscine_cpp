/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:45:50 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 12:24:12 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

#include <iostream>

#include <cstdlib>

#define RRF RobotomyRequestForm

void requestRobotomy(std::string target) {
	std::cout << "* drill noises *" << std::endl;

	if (random() % 2)
		std::cout << target << " has been robotomized" << std::endl;
	else
		std::cout << "Failed to robotomize " << target << std::endl;
}

RRF::RobotomyRequestForm(std::string target) :
Form("robotomy", target, 72, 45, requestRobotomy) { }

void RRF::_() { }
