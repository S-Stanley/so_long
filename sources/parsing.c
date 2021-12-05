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

t_parsing	new_line_parsing(t_parsing parsing)
{
	parsing.map = lst_push_back(parsing.arr, parsing.map);
	free_that_matrice(parsing.arr);
	parsing.arr = NULL;
	parsing.i++;
	return (parsing);
}

unsigned int	is_white_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}

t_map	*get_map_from_file(int fd, t_parsing parsing, int reading)
{
	char			*buffer;
	int				buffer_size;

	buffer_size = 5;
	while (reading > 0)
	{
		buffer = malloc(sizeof(char *) * (buffer_size + 1));
		if (!buffer)
			print_and_exit("Error while allocating buffer\n");
		reading = read(fd, buffer, buffer_size);
		buffer[reading] = 0;
		parsing.i = 0;
		while (buffer[parsing.i])
		{
			if (buffer[parsing.i] == '\n')
				parsing = new_line_parsing(parsing);
			else
			{
				while (is_white_space(buffer[parsing.i]))
					parsing.i++;
				parsing.arr = push_arr(
						parsing.arr, create_str_from_char(buffer[parsing.i++]));
			}
		}
		free(buffer);
	}
	parsing.map = lst_push_back(parsing.arr, parsing. map);
	free_that_matrice(parsing.arr);
	return (parsing.map);
}

t_map	*setup_map(const char *file)
{
	int				fd;
	int				reading;
	t_parsing		parsing;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_and_exit("Cannot open file\n");
	reading = 2;
	parsing.map = NULL;
	parsing.arr = NULL;
	parsing.i = 0;
	parsing.map = get_map_from_file(fd, parsing, reading);
	close(fd);
	return (parsing.map);
}
