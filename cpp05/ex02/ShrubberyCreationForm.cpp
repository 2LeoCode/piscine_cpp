/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:55:40 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 00:25:29 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <string>

#define SCF ShrubberyCreationForm

void createShrubbery(std::string target) {
	std::ofstream	out((target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);

	if (!out) throw std::runtime_error("Failed to open output file");
	out << "         v" << std::endl <<
	"        >X<" << std::endl <<
	"         A" << std::endl <<
	"        d$b" << std::endl <<
	"      .d\\$$b." << std::endl <<
	"    .d$i$$\\$$b." << std::endl <<
	"       d$$@b" << std::endl <<
	"      d\\$$$ib" << std::endl <<
	"    .d$$$\\$$$b" << std::endl <<
	"  .d$$@$$$$\\$$ib." << std::endl <<
	"      d$$i$$b" << std::endl <<
	"     d\\$$$$@$b" << std::endl <<
	"  .d$@$$\\$$$$$@b." << std::endl <<
	".d$$$$i$$$\\$$$$$$b." << std::endl <<
	"        ###" << std::endl <<
	"        ###" << std::endl <<
	"        ### mh" << std::endl;
	out.close();
}

SCF::ShrubberyCreationForm(std::string target) :
Form("shrubbery creation", target, 145, 137, createShrubbery) { }

void SCF::__abstract__() { }
