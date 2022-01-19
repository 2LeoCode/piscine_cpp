/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:53:50 by crochu            #+#    #+#             */
/*   Updated: 2021/11/03 12:24:34 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Form.hpp"
#include "UniquePtr.hpp"

#include <iostream>

int	main(void) {
	Intern kevin;
	UniquePtr< Form > rob, shrub, presidential;

	try {
		rob = kevin.makeForm("robotomy request", "A-01");
		shrub = kevin.makeForm("shrubbery creation", "B-00");
		presidential = kevin.makeForm("presidential pardon", "B-01");
		kevin.makeForm("foo", "foo");
		kevin.makeForm("bar", "bar");
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}
