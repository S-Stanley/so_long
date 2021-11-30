#include "main.h"

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
