/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:34:17 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/04 20:34:18 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_and_exit(char *message)
{
	printf("Error\n");
	printf("%s", message);
	exit(0);
}

void	exit_game(t_window window)
{
	free_images(window.img_start, window);
	free_lst(window.map_start);
	mlx_destroy_window(window.mlx, window.win);
	mlx_destroy_display(window.mlx);
	free(window.mlx);
	exit(0);
}

int	on_buton_press(t_window *window)
{
	exit_game(*(window));
	return (0);
}

int	on_key_press(int keycode, t_window *window)
{
	t_player	player;

	player = get_player_position(window->map);
	if (keycode == 65307)
		exit_game(*(window));
	if (keycode == 65362 || keycode == 119)
		*(window) = move_top(window->map, player, *(window));
	if (keycode == 65364 || keycode == 115)
		*(window) = move_bottom(window->map, player, *(window));
	if (keycode == 65361 || keycode == 97)
		*(window) = move_left(window->map, player, *(window));
	if (keycode == 65363 || keycode == 100)
		*(window) = move_right(window->map, player, *(window));
	return (0);
}
