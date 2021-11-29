# include "main.h"

t_map	*lst_push_back(char **line, t_map *map)
{
	t_map	*new;
	t_map	*tmp;

	new = new_lst(line);
	if (!new)
		return (NULL);
	if (!map)
		return (new);
	tmp = map;
	while (map->next)
		map = map->next;
	map->next = new;
	return (tmp);
}

char	**copy_matrice(char **matrice)
{
	char			**to_return;
	unsigned int	i;

	i = 0;
	to_return = malloc(sizeof(char *) * (count_len_matrice(matrice) + 1));
	while (matrice[i])
	{
		to_return[i] = strdup(matrice[i]);
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}

t_map	*new_lst(char **line)
{
	t_map  	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	int i = 0;
	while (line[i])
	{
		printf("%s\n", line[i]);
		i++;
	}
	printf("-------\n");
	map->line = copy_matrice(line);
	map->next = NULL;
	return (map);
}

void	print_lst(t_map *map)
{
	unsigned int	i;

	i = 0;
	if (!map)
		return ;
	printf("*****\n");
	while (map)
	{
		while (map->line[i])
		{
			printf("%s\n", map->line[i]);
			i++;
		}
		printf("-------\n");
		map = map->next;
	}
}