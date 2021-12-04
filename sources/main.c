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

int	main(int argc, char **argv)
{
	t_map			*map;
	t_window		window;

	(void)argc;
	map = setup_map(argv[1]);
	window = setup_window(map);
	window.img = draw_map(window);
	get_player_position(map);
	mlx_hook(window.win, 2, 1L << 0, on_key_press, &window);
	mlx_loop(window.mlx);
	return (0);
}
