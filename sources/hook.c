#include "main.h"

int	on_key_press(int keycode, t_window *window)
{
	t_player	player;

	player = get_player_position(window->map);
	if (keycode == 65307)
	{
		mlx_destroy_window(window->mlx, window->win);
		mlx_destroy_display(window->mlx);
		free_lst(window->map);
		exit(0);
	}
	if (keycode == 65362 || keycode == 97)
		window->map = move_top(window->map, player, *(window));
	if (keycode == 65364 || keycode == 119)
		window->map = move_bottom(window->map, player, *(window));
	// if (keycode == 65361 || keycode == 115)
	// 	move_left();
	// if (keycode == 65363 || keycode == 100)
	// 	move_right();
	return (0);
}
