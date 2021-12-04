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

t_map	*setup_map(const char *file)
{
	int				fd;
	char			*buffer;
	int				buffer_size;
	int				reading;
	unsigned int	i;
	char			**arr;
	t_map			*map;

	buffer_size = 5;
	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		print_and_exit("Cannot open file\n");
	reading = 2;
	arr = NULL;
	map = NULL;
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
			{
				arr = push_arr(arr, create_str_from_char(buffer[i]));
				i++;
			}
		} 
		free(buffer);
	}
	map = lst_push_back(arr, map);
	free_that_matrice(arr);
	close(fd);
	return (map);
}