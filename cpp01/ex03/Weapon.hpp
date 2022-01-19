/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:14:54 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/19 23:51:13 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class Weapon {
	public:
		Weapon(std::string type);
		~Weapon();

		const std::string	&getType(void) const;
		void				setType(std::string type);

	private:
		std::string	_type;
};
