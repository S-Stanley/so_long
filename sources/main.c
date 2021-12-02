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

int	main(void)
{
	t_map			*map;
	t_window		window;

	map = setup_map();
	window = setup_window(map);
	// // put_img(window, "textures/dauphin.xpm", 50, 50);
	// // window.map = map;
	draw_map(window);
	get_player_position(map);
	mlx_hook(window.win, 2, 1L << 0, on_key_press, &window);
	mlx_loop(window.mlx);
	return (0);
}

/*
	put_img(mlx, window, "textures/img.xpm", 5, 5);
	put_pixel_via_img(mlx, window, 0, 0, 0x00D8FF);
	put_pixel(mlx, window, 5, 5, 0x00D8FF);
*/