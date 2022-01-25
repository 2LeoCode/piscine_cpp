/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 16:55:40 by crochu            #+#    #+#             */
/*   Updated: 2022/01/25 23:29:12 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

#include <fstream>
#include <string>

#define ShrubberyCreationForm ShrubberyCreationForm

void createShrubbery(std::string target) {
	std::ofstream	out((target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);

	if (!out) throw std::runtime_error("Failed to open output file");
	out <<
		"         v\n"
		"        >X<\n"
		"         A\n"
		"        d$b\n"
		"      .d\\$$b.\n"
		"    .d$i$$\\$$b.\n"
		"       d$$@b\n"
		"      d\\$$$ib\n"
		"    .d$$$\\$$$b\n"
		"  .d$$@$$$$\\$$ib.\n"
		"      d$$i$$b\n"
		"     d\\$$$$@$b\n"
		"  .d$@$$\\$$$$$@b.\n"
		".d$$$$i$$$\\$$$$$$b.\n"
		"        ###\n"
		"        ###\n"
		"        ### mh" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:	Form("shrubbery creation", target, 145, 137, createShrubbery) { }

void ShrubberyCreationForm::m__abstract__(void) const { }
