/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Karen.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 01:21:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 17:50:20 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Karen.hpp"

#include <iostream>

std::string	Karen::_debugMsg("I love to get extra bacon for my "
"XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!");

std::string	Karen::_infoMsg("I cannot believe adding extra bacon cost more money."
"You don’t put enough! If you did I would not have to ask for it!");

std::string	Karen::_warningMsg("I think I deserve to have some extra bacon for "
"free. I’ve been coming here for years and you just started working here last "
"month.");

std::string	Karen::_errorMsg("This is unacceptable, I want to speak to the "
"manager now.");

Trie< Karen::ComplainFun >	Karen::_data;

bool	Karen::m_init_trie(void) {
	_data.insert("DEBUG", &Karen::debug);
	_data.insert("INFO", &Karen::info);
	_data.insert("WARNING", &Karen::warning);
	_data.insert("ERROR", &Karen::error);
	return true;
}

Karen::Karen() { static bool init = m_init_trie(); (void)init; }

Karen::~Karen() { }

void	Karen::debug(void) {
	std::cout << _debugMsg << std::endl;
}

void	Karen::info(void) {
	std::cout << _infoMsg << std::endl;
}

void	Karen::warning(void) {
	std::cout << _warningMsg << std::endl;
}

void	Karen::error(void) {
	std::cout << _errorMsg << std::endl;
}

void	Karen::complain(std::string level) {
	(this->*_data.search(level.c_str()))();
}
