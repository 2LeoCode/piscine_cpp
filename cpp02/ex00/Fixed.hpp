/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 17:48:52 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/20 18:19:30 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

class Fixed {
	public:
		Fixed();
		~Fixed();

		Fixed(const Fixed &src);
		
		Fixed	&operator=(const Fixed src);

		int		getRawBits(void) const;
		void	setRawBits(int rawBits);

	private:
		int					m_rawBits;

		static const int	m_nbBits;
};
