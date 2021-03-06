/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:34:01 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/04 20:34:03 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_player	get_player_position(t_map *map)
{
	unsigned int	i;
	t_player		player;

	player.pos_x = 0;
	player.pos_y = 0;
	while (map)
	{
		i = 0;
		player.pos_x = 0;
		while (map->line[i])
		{
			if (map->line[i][0] == 'P')
				return (player);
			player.pos_x++;
			i++;
		}
		player.pos_y++;
		map = map->next;
	}
	return (player);
}
