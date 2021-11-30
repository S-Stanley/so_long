/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:51:35 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 00:51:36 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	draw_square(void *mlx, void *window, unsigned int start_x, unsigned int start_y, int color, int size_x, unsigned int max_size_y)
{
	unsigned int	max_y;
	unsigned int	max_x;
	unsigned int	tmp_y;

	max_y = start_y + max_size_y;
	tmp_y = start_y;
	max_x = start_x + (unsigned int)size_x;
	while (start_x <= max_x)
	{
		start_y = tmp_y;
		while (start_y <= max_y)
		{
			put_pixel(mlx, window, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}

void	draw_line(t_window win, char **line, unsigned int line_nbr)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;

	i = 0;
	x = 0;
	while (line[i])
	{
		y = 0 + (win.max_sq_y * (line_nbr - 1));
		draw_square(win.mlx, win.win, x, y, get_color(line[i]), win.max_sq_x, win.max_sq_y);
		i++;
		x = x + win.max_sq_x;
	}
}
