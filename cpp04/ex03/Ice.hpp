/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:20:02 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:32:50 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

struct Ice : public AMateria {
	Ice();
	~Ice();

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
};
