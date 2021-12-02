#include "main.h"

t_player	get_player_position(t_map *map)
{
	unsigned int	i;
	t_player		player;

	player.pos_x = 0;
	player.pos_y = 0;
	while (map)
	{
		i = 0;
		player.pos_x = 0;
		while (map->line[i])
		{
			if (map->line[i][0] == 'P')
			{
				printf("Player position -> %d:%d\n", player.pos_x, player.pos_y);
				return (player);
			}
			player.pos_x++;
			i++;
		}
		player.pos_y++;
		map = map->next;
	}
	return (player);
}
