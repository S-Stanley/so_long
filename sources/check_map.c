/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:36:19 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/04 23:36:21 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	is_map_rectangular(t_map *map)
{
	unsigned int	len_line;
	t_map			*tmp;

	tmp = map;
	len_line = count_len_matrice(map->line);
	map = map->next;
	while (map)
	{
		if (count_len_matrice(map->line) != len_line)
		{
			free_lst(tmp);
			print_and_exit("This map is not rectangular\n");
		}
		map = map->next;
	}
}

void	check_playable(t_map *map)
{
	(void)map;
}

void	is_map_closed(t_map *map)
{
	(void)map;
}

void	check_map(t_map *map)
{
	is_map_closed(map);
	check_playable(map);
	is_map_rectangular(map);
}
