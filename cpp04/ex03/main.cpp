/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:23:25 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:34:28 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "ICharacter.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "UniquePtr.hpp"
#include "UniqueArrPtr.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

int	main(void) {
	srandom(time(NULL));
	UniqueArrPtr< UniquePtr< ICharacter > >	characters;
	UniqueArrPtr< UniquePtr< AMateria > >	materias;
	UniquePtr< ICharacter >					dummy;

	
	return 0;
}
