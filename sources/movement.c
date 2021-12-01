#include "main.h"

t_map	*move_top(t_map	*map, t_player player)
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
	free(map->line[player.pos_x]);
	map->line[player.pos_x] = ft_strdup("P");
	map = map->next;
	map->line[player.pos_x] = ft_strdup("0");
	return (tmp);
}
