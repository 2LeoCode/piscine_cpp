/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsuardi <lsuardi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:37:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 23:10:45 by lsuardi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

#include "IMateriaSource.hpp"

#ifndef INV_LMIT
# define INV_LIMIT 4
#endif

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		~MateriaSource();

		MateriaSource	&operator =(const MateriaSource&);

		void		learnMateria(AMateria*);
		void		unlearnMateria(int);
		AMateria	*createMateria(const std::string&);

		struct EInventoryFull {
			const char	*what(void) const throw ();
		};
	private:
		AMateria	*m_inventory[INV_LIMIT];
		bool		m_occupied[INV_LIMIT];
};
