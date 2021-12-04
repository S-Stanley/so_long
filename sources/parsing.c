/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:29:23 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 01:29:24 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	print_and_exit(char *message)
{
	printf("Error\n");
	printf("%s", message);
	exit(0);
}

char	*create_str_from_char(char c)
{
	char	*to_return;

	to_return = malloc(sizeof(char *) * 2);
	if (!to_return)
		return (NULL);
	to_return[0] = c;
	to_return[1] = 0;
	return (to_return);
}

typedef struct s_parsing {
	t_map	*map;
	char	**arr;
}	t_parsing;

t_map	*get_map_from_file(int fd, t_map *map, int reading, char **arr)
{
	char			*buffer;
	int				buffer_size;
	unsigned int	i;

	buffer_size = 5;
	while (reading > 0)
	{
		buffer = malloc(sizeof(char *) * (buffer_size + 1));
		if (!buffer)
			print_and_exit("Error while allocating buffer\n");
		reading = read(fd, buffer, buffer_size);
		buffer[reading] = 0;
		i = 0;
		while (buffer[i])
		{
			if (buffer[i] == '\n')
			{
				map = lst_push_back(arr, map);
				free_that_matrice(arr);
				arr = NULL;
				i++;
			}
			else
				arr = push_arr(arr, create_str_from_char(buffer[i++]));
		}
		free(buffer);
	}
	map = lst_push_back(arr, map);
	free_that_matrice(arr);
	return (map);
}

t_map	*setup_map(const char *file)
{
	int				fd;
	int				reading;
	t_map			*map;
	char			**arr;

	fd = open(file, O_RDONLY);
	if (!fd)
		print_and_exit("Cannot open file\n");
	reading = 2;
	map = NULL;
	arr = NULL;
	map = get_map_from_file(fd, map, reading, arr);
	close(fd);
	return (map);
}
