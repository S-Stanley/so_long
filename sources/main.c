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

t_window	setup_window(t_map *map)
{
	t_window	win;

	win.size_win_x = 1000;
	win.size_win_y = 500;
	win.mlx = mlx_init();
	win.win = mlx_new_window(
			win.mlx,
			win.size_win_x,
			win.size_win_y,
			"so_long");
	if (count_len_lst(map) > 0)
	{
		win.max_sq_x = win.size_win_x / count_len_matrice(map->line);
		win.max_sq_y = win.size_win_y / count_len_lst(map);
	}
	else
	{
		win.max_sq_y = 0;
		win.max_sq_x = 0;
	}
	return (win);
}

int	main(void)
{
	int				size_x;
	t_map			*map;
	unsigned int	line_nbr;
	unsigned int	max_size_y;
	t_window		window;

	map = setup_map();
	window = setup_window(map);
	line_nbr = 1;
	while (map)
	{
		draw_line(window, map->line, line_nbr);
		map = map->next;
		line_nbr++;
	}
	mlx_loop(window.mlx);
	return (0);
}

/*
	put_img(mlx, window, "textures/img.xpm", 5, 5);
	put_pixel_via_img(mlx, window, 0, 0, 0x00D8FF);
	put_pixel(mlx, window, 5, 5, 0x00D8FF);
*/