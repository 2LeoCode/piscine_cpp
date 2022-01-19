/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:57 by crochu            #+#    #+#             */
/*   Updated: 2021/11/02 16:03:18 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
	Form generic, named("B-35"), a42("A-42", 100, 50), a01("A-01", 50, 1);
	Bureaucrat a("kevin", 150), b("joe", 100), c("john", 50), d("boss", 1);

	a.signForm(a42), a.signForm(a01), a.executeForm(generic);
	d.executeForm(generic), a.signForm(generic), a.signForm(named);
	b.signForm(a42), c.signForm(a01), a.executeForm(generic);
	a.executeForm(a42), d.executeForm(a01), c.executeForm(a42);
	return 0;
}
