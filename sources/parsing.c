/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <sserbin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:29:23 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/08 01:03:24 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

t_parsing	push_arr_loop(t_parsing parsing, char *buffer)
{
	while (is_white_space(buffer[parsing.i]))
		parsing.i++;
	parsing.arr = push_arr(
			parsing.arr, create_str_from_char(buffer[parsing.i++]));
	return (parsing);
}

void	free_and_exit_error_buff(char *buffer, t_parsing parsing)
{
	free(buffer);
	free_lst(parsing.map);
	print_and_exit("Error while allocating buffer\n");
}

t_parsing	new_line_buffer(t_parsing parsing, char *buffer)
{
	if (buffer[parsing.i] == '\n')
	{
		if (parsing.arr)
			parsing = new_line_parsing(parsing);
		else
			parsing.i++;
	}
	else
		parsing = push_arr_loop(parsing, buffer);
	return (parsing);
}

t_parsing	arr_not_empty(t_parsing parsing)
{
	parsing.map = lst_push_back(parsing.arr, parsing. map);
	free_that_matrice(parsing.arr);
	return (parsing);
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
			free_and_exit_error_buff(buffer, parsing);
		reading = read(fd, buffer, buffer_size);
		buffer[reading] = 0;
		parsing.i = 0;
		while (buffer[parsing.i])
			parsing = new_line_buffer(parsing, buffer);
		free(buffer);
	}
	if (parsing.arr)
		parsing = arr_not_empty(parsing);
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
	if (!parsing.map)
		exit(0);
	return (parsing.map);
}
