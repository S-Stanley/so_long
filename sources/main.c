/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <sserbin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:01:32 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/08 01:03:40 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "../minilibx-linux/mlx.h"
#include <string.h>

void	is_map_ber(const char *str, const char *ext)
{
	unsigned int	i;
	unsigned int	x;

	i = 0;
	x = 0;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i] || ext[x])
	{
		if (str[i] != ext[x])
			print_and_exit("This is not .ber map\n");
		i++;
		x++;
	}
}

int	main(int argc, char **argv)
{
	t_map			*map;
	t_window		window;

	if (argc != 2)
		print_and_exit("Please give one map in arg");
	is_map_ber(argv[1], ".ber");
	map = setup_map(argv[1]);
	check_map(map);
	window = setup_window(map);
	window.img = draw_map(window);
	window.img_start = window.img;
	get_player_position(map);
	mlx_hook(window.win, 2, 1L << 0, on_key_press, &window);
	mlx_hook(window.win, 33, 1L << 5, on_buton_press, &window);
	mlx_loop(window.mlx);
	return (0);
}
