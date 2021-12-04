/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:33:47 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/04 20:33:48 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_window	move_top(t_map	*map, t_player player, t_window win)
{
	unsigned int	i;
	t_map			*tmp;

	tmp = map;
	i = 0;
	while (player.pos_y > 1)
	{
		map = map->next;
		player.pos_y--;
	}
	if (!can_he_move_here(map->line[player.pos_x][0], win))
		return (win);
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("P");
	map = map->next;
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("0");
	win.map = tmp;
	win.img = draw_map(win);
	win.nb_move = print_move(win.nb_move);
	return (win);
}

unsigned int	can_he_move_bottom(t_map *map, t_player player, t_window win)
{
	t_map	*tmp;

	tmp = map;
	while (--player.pos_y >= 0)
		map = map->next;
	tmp = map->next;
	if (!can_he_move_here(tmp->line[player.pos_x][0], win))
		return (0);
	return (1);
}

t_window	move_bottom(t_map *map, t_player player, t_window win)
{
	t_map	*tmp;

	tmp = map;
	if (!can_he_move_bottom(map, player, win))
		return (win);
	while (--player.pos_y >= 0)
		map = map->next;
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("0");
	map = map->next;
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("P");
	win.map = tmp;
	win.img = draw_map(win);
	win.nb_move = print_move(win.nb_move);
	return (win);
}

t_window	move_left(t_map *map, t_player player, t_window win)
{
	t_map	*tmp;

	tmp = map;
	while (--player.pos_y >= 0)
		map = map->next;
	if (!can_he_move_here(map->line[player.pos_x - 1][0], win))
		return (win);
	free(map->line[player.pos_x - 1]);
	map->line[player.pos_x - 1] = ft_strdup("P");
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("0");
	win.map = tmp;
	win.img = draw_map(win);
	win.nb_move = print_move(win.nb_move);
	return (win);
}

t_window	move_right(t_map *map, t_player player, t_window win)
{
	t_map	*tmp;

	tmp = map;
	while (--player.pos_y >= 0)
		map = map->next;
	if (!can_he_move_here(map->line[player.pos_x + 1][0], win))
		return (win);
	free(map->line[player.pos_x + 1]);
	map->line[player.pos_x + 1] = ft_strdup("P");
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("0");
	win.map = tmp;
	win.img = draw_map(win);
	win.nb_move = print_move(win.nb_move);
	return (win);
}
