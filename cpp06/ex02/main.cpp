/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crochu <crochu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:53:23 by crochu            #+#    #+#             */
/*   Updated: 2021/11/06 17:17:01 by crochu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "UniquePtr.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

#define SC static_cast
#define DC dynamic_cast

Base *newA(void) { return new A; }
Base *newB(void) { return new B; }
Base *newC(void) { return new C; }

Base *generate(void) {
	return ((Base *(*[])()){ newA, newB, newC }[random() % 3]());
}

void identify(Base *ptr) {
	if (DC< A* >(ptr)) std::cout << 'A' << std::endl;
	else if (DC< B* >(ptr)) std::cout << 'B' << std::endl;
	else if (DC< C* >(ptr)) std::cout << 'C' << std::endl;
}

void identify(Base &ref) {
	try { SC< void >(DC< A& >(ref)), std::cout << 'A' << std::endl; }
	catch (std::exception &e) { SC< void >(e); }
	try { SC< void >(DC< B& >(ref)), std::cout << 'B' << std::endl; }
	catch (std::exception &e) { SC< void >(e); }
	try { SC< void >(DC< C& >(ref)), std::cout << 'C' << std::endl; }
	catch (std::exception &e) { SC< void >(e); }
}

int main(void) {
	srandom(time(NULL));
	UniquePtr< Base > p1, p2, p3;

	try {
		p1 = generate(), p2 = generate(), p3 = generate();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	identify(p1.ptr()), identify(p2.ptr()), identify(p3.ptr());
	std::cout << std::endl;
	identify(*p1), identify(*p2), identify(*p3);
	return 0;
}
