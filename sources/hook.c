#include "main.h"

int	on_key_press(int keycode, t_window *window)
{
	t_player	player;

	player = get_player_position(window->map);
	if (keycode == 65307)
		exit(0);
	if (keycode == 65362 || keycode == 97)
		window->map = move_top(window->map, player, *(window));
	if (keycode == 65364 || keycode == 119)
		window->map = move_bottom(window->map, player, *(window));
	// if (keycode == 65361 || keycode == 115)
	// 	move_left();
	// if (keycode == 65363 || keycode == 100)
	// 	move_right();
	write(1, ft_itoa(keycode), ft_strlen(ft_itoa(keycode)));
	write(1, "\n", 1);
	return (0);
}
