/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 15:37:21 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 18:03:23 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstddef>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource {
	public:
		MateriaSource();
		MateriaSource(const MateriaSource&);
		~MateriaSource();

		MateriaSource	&operator =(const MateriaSource&);

		void		learnMateria(AMateria*);
		AMateria	*createMateria(const std::string&) const;

	private:
		AMateria	*m_inventory;
		std::size_t	m_item_cnt;
};
