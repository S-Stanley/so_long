/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:01:32 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/21 19:01:32 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "../minilibx-linux/mlx.h"
#include <string.h>

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

void	get_file_data(const char *file)
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
	{
		printf("Error\n Cannot open file\n");
		exit (0);
	}
	reading = 2;
	arr = NULL;
	map = NULL;
	while (reading > 0)
	{
		buffer = malloc(sizeof(char *) * (buffer_size + 1));
		if (!buffer)
		{
			printf("Error while allocating buffer\n");
			exit(0);
		}
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
	// print_matrice(arr);
	map = lst_push_back(arr, map);
	free_that_matrice(arr);
	print_lst(map);
	free_lst(map);
	close(fd);
}

int	main(int argc, char **argv)
{
	// t_map			*map;
	// t_window		window;

	(void)argc;
	get_file_data(argv[1]);
	// map = setup_map();
	// window = setup_window(map);
	// window.img = draw_map(window);
	// get_player_position(map);
	// mlx_hook(window.win, 2, 1L << 0, on_key_press, &window);
	// mlx_loop(window.mlx);
	return (0);
}
