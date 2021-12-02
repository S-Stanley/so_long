/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:43:01 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 00:43:02 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_map	*lst_push_back(char **line, t_map *map)
{
	t_map	*new;
	t_map	*tmp;

	new = new_lst(line);
	if (!new)
		return (NULL);
	if (!map)
		return (new);
	tmp = map;
	while (map->next)
		map = map->next;
	map->next = new;
	return (tmp);
}

t_map	*new_lst(char **line)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->line = copy_matrice(line);
	map->next = NULL;
	return (map);
}

void	print_lst(t_map *map)
{
	if (!map)
		return ;
	while (map)
	{
		print_matrice(map->line);
		map = map->next;
	}
}

unsigned int	count_len_lst(t_map *map)
{
	unsigned int	i;

	i = 0;
	if (!map)
		return (0);
	while (map)
	{
		i++;
		map = map->next;
	}
	return (i);
}

void	free_lst(t_map *map)
{
	t_map	*tmp;

	tmp = map;
	while (map)
	{
		tmp = map->next;
		free_that_matrice(map->line);
		free(map);
		map = tmp;
	}
}
