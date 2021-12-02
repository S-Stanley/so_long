#include "main.h"

t_map	*move_top(t_map	*map, t_player player, t_window win)
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
	if (map->line[player.pos_x][0] == '1')
		return (tmp);
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("P");
	map = map->next;
	map->line[player.pos_x] = ft_strdup("0");
	win.map = tmp;
	draw_map(win, win.map);
	return (tmp);
}


unsigned int	can_he_move_bottom(t_map *map, t_player player)
{

}

t_map	*move_bottom(t_map	*map, t_player player, t_window win)
{
	t_map	*tmp;

	tmp = map;
	if (can_he_move_bottom(map, player))
	{
		
	}
	(void)player;
	(void)win;
	return (tmp);
}