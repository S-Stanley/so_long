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

void	draw_square(t_window win, int start_x, int start_y, int color)
{
	unsigned int	max_y;
	unsigned int	max_x;
	unsigned int	tmp_y;

	max_y = start_y + win.max_sq_y;
	tmp_y = start_y;
	max_x = start_x + (unsigned int)win.max_sq_x;
	while (start_x <= (int)max_x)
	{
		start_y = tmp_y;
		while (start_y <= (int)max_y)
		{
			put_pixel(win, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}

void	draw_map(t_window window)
{
	unsigned int	line_nbr;

	line_nbr = 1;
	while (window.map)
	{
		draw_line(window, window.map->line, line_nbr);
		window.map = window.map->next;
		line_nbr++;
	}
}

char	*get_image_path(char code)
{
	if (code == 'P')
		return ("textures/42/dauphin.xpm");
	if (code == 'C')
		return ("textures/2x42/coin.xpm");
	if (code == 'E')
		return ("textures/42/door.xpm");
	if (code == '0')
		return ("textures/42/grass.xpm");
	return ("textures/42/wall.xpm");
}

void	draw_img(t_window win, int start_x, int start_y, char *path)
{
	put_img(win, path, start_x, start_y);
}

void	draw_line(t_window win, char **line, unsigned int line_nbr)
{
	int				x;
	int				y;
	unsigned int	i;

	i = 0;
	x = 0;
	while (line[i])
	{
		y = 0 + (win.max_sq_y * (line_nbr - 1));
		draw_img(win, x, y, get_image_path(line[i][0]));
		i++;
		x = x + win.max_sq_x;
	}
}
