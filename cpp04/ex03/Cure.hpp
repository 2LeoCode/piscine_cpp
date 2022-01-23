/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:26:23 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 15:31:05 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

struct Cure : public AMateria {
	Cure();
	~Cure();

	virtual AMateria	*clone(void) const;
	virtual void		use(ICharacter &target);
};

#endif //CURE_HPP
