/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MindOpen.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 02:51:37 by crochu            #+#    #+#             */
/*   Updated: 2021/11/09 03:16:25 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

#define MO MindOpen
#define Constructor MO
#define Destructor ~MO

class MindOpen {
	public:
		Constructor();
		Destructor();

		void execute(std::istream &input);

		struct EInvalidInput : public std::exception {
			const char *what() const throw ();
		};
		struct EInvalidConfig : public std::exception {
			const char *what() const throw ();
		};
	private:
		char _op[10];
};
