/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:38:44 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/04 20:38:45 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	check_map_case(t_map *map)
{
	unsigned int	i;

	while (map)
	{
		i = 0;
		while (map->line[i])
		{
			if (map->line[i][0] != '0' && map->line[i][0] != '1' &&
					map->line[i][0] != 'E' &&
					map->line[i][0] != 'C' &&
					map->line[i][0] != 'P')
				return (0);
			i++;
		}
		map = map->next;
	}
	return (1);
}

void	print_and_exit_game(char *str, t_window win)
{
	put_str(str);
	exit_game(win);
}

void	should_exit(char pos, t_window win)
{
	unsigned int	i;
	t_map			*tmp;

	tmp = win.map;
	if (pos != 'E')
		return ;
	while (win.map)
	{
		i = 0;
		while (win.map->line[i])
		{
			if (win.map->line[i][0] == 'C')
				return ;
			i++;
		}
		win.map = win.map->next;
	}
	win.map = tmp;
	exit_game(win);
}
