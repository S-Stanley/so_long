/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <sserbin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 23:36:19 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/07 21:18:18 by sserbin          ###   ########.fr       */
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

unsigned int	check_playable(t_map *map)
{
	unsigned int	count_collectible;
	unsigned int	count_exit;
	unsigned int	count_start_pos;
	int				i;

	count_collectible = 0;
	count_exit = 0;
	count_start_pos = 0;
	while (map)
	{
		i = -1;
		while (map->line[++i])
		{
			if (map->line[i][0] == 'E')
				count_exit++;
			if (map->line[i][0] == 'C')
				count_collectible++;
			if (map->line[i][0] == 'P')
				count_start_pos++;
		}
		map = map->next;
	}
	if (!count_collectible || !count_exit || !count_start_pos)
		return (0);
	return (1);
}

unsigned int	is_map_closed(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (map->line[i])
	{
		if (map->line[i][0] != '1')
			return (0);
		i++;
	}
	while (map->next)
	{
		if (map->line[0][0] != '1')
			return (0);
		if (map->line[count_len_matrice(map->line) - 1][0] != '1')
			return (0);
		map = map->next;
	}
	i = 0;
	while (map->line[i])
	{
		if (map->line[i][0] != '1')
			return (0);
		i++;
	}
	return (1);
}

unsigned int	check_textures(char *to_check)
{
	unsigned int	i;
	int				fd;

	i = 0;
	while (to_check[i])
	{
		fd = open(get_image_path('P'), O_RDONLY);
		if (fd == -1)
		{
			close(fd);
			return (0);
		}
		close (fd);
		i++;
	}
	return (1);
}

void	check_map(t_map *map)
{
	if (!is_map_closed(map))
	{
		free_lst(map);
		print_and_exit("Map is not closed\n");
	}
	if (!check_playable(map))
	{
		free_lst(map);
		print_and_exit("Missing one, collectible, exit or start pos\n");
	}
	is_map_rectangular(map);
	if (!check_textures("PCE10"))
	{
		free_lst(map);
		print_and_exit("Cannot get at leat one of the texture\n");
	}
	if (!check_map_case(map))
	{
		free_lst(map);
		print_and_exit("The map is corrupt, one item should not be there\n");
	}
}
