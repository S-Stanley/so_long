/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:38:39 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/04 20:38:40 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	can_he_move_here(char pos, t_window win)
{
	should_exit(pos, win);
	if (pos == '0' || pos == 'C')
		return (1);
	return (0);
}

unsigned int	print_move(unsigned int nb_move)
{
	nb_move++;
	printf("Move number: %d\n", nb_move);
	return (nb_move);
}
