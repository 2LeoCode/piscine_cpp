/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:30:37 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 18:01:47 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"

class Character : public ICharacter {
	public:
		Character();
		~Character();

		Character(const ICharacter &other);
		Character(std::string name);

		Character	&operator=(const ICharacter &other);

		virtual std::string const	&getName(void) const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
		void						deleteInventory(void);

	private:
		std::string	m_name;
		AMateria	*m_inventory[4];
		int			m_itemCnt;
};
