/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:01:32 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/21 19:01:32 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "../minilibx-linux/mlx.h"
#include <string.h>

t_player	get_player_position(t_map *map)
{
	unsigned int	i;
	t_player		player;

	player.posX = 0;
	player.posY = 0;
	while (map)
	{
		i = 0;
		player.posX = 0;
		while (map->line[i])
		{
			if (map->line[i][0] == 'P')
			{
				printf("Player position -> %d:%d\n", player.posX, player.posY);
				return (player);
			}
			player.posX++;
			i++;
		}
		player.posY++;
		map = map->next;
	}
}

t_map	*move_top(t_map	*map, t_player player)
{
	unsigned int	i;
	t_map			*tmp;
	int				posY;

	tmp = map;
	posY = player.posY;
	i = 0;
	while (posY > 1)
	{
		map = map->next;
		posY--;
	}
	free(map->line[player.posX]);
	map->line[player.posX] = ft_strdup("P");
	map = map->next;
	map->line[player.posX] = ft_strdup("0");
	return (tmp);
}

void	draw_map(t_window window, t_map *map)
{
	unsigned int	line_nbr;

	line_nbr = 1;
	while (map)
	{
		draw_line(window, map->line, line_nbr);
		map = map->next;
		line_nbr++;
	}
}

int	key_hook(int keycode, t_window *window)
{
	t_player	player;

	player = get_player_position(window->map);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 97)
	{
		window->map = move_top(window->map, player);
		draw_map(*(window), window->map);
	}
	// if (keycode == 65364 || keycode == 119)
	// 	move_bottom();
	// if (keycode == 65361 || keycode == 115)
	// 	move_left();
	// if (keycode == 65363 || keycode == 100)
	// 	move_right();
	write(1, ft_itoa(keycode), ft_strlen(ft_itoa(keycode)));
	write(1, "\n", 1);
	return (0);
}

int	main(void)
{
	t_map			*map;
	t_window		window;

	map = setup_map();
	window = setup_window(map);
	window.map = map;
	draw_map(window, map);
	get_player_position(map);
	mlx_hook(window.win, 2, 1L<<0, key_hook, &window);
	mlx_loop(window.mlx);
	return (0);
}

/*
	put_img(mlx, window, "textures/img.xpm", 5, 5);
	put_pixel_via_img(mlx, window, 0, 0, 0x00D8FF);
	put_pixel(mlx, window, 5, 5, 0x00D8FF);
*/