#include "main.h"

t_map	*setup_map()
{
	t_map	*map;

	char			*line1[] = {"0", "1", "0", "0", "1", 0};
	char			*line2[] = {"0", "0", "1", "0", "1", 0};
	char			*line3[] = {"0", "0", "1", "0", "1", 0};
	char			*line4[] = {"1", "0", "0", "1", "0", 0};
	char			*line5[] = {"0", "1", "1", "0", "0", 0};

	map = NULL;
	map = lst_push_back(line1, map);
	map = lst_push_back(line2, map);
	map = lst_push_back(line3, map);
	map = lst_push_back(line4, map);
	map = lst_push_back(line5, map);
	return (map);
}
