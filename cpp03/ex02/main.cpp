/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Leo Suardi <lsuardi@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 21:42:26 by Leo Suardi        #+#    #+#             */
/*   Updated: 2022/01/23 17:52:27 by Leo Suardi       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void) {
	FragTrap	fraggy("Fraggy");

	fraggy.enableDebugInfos();
	fraggy.attack("giant dragon");
	fraggy.highFiveGuys();
	return (0);
}
