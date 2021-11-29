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

void	put_img(void *mlx, void *window, char *path, int width, int height)
{
	void	*img;
	char	*str;

	img = mlx_xpm_file_to_image(mlx, path, &width, &height);
	if (!img)
	{
		str = "Failed to get xpm image\n";
		write(1, str, ft_strlen(str));
		exit(0);
	}
	mlx_put_image_to_window(mlx, window, img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	put_pixel(void *mlx, void *window, int x, int y, int color)
{
	mlx_pixel_put(mlx, window, x, y, color);
}

void	put_pixel_via_img(void *mlx, void *window, int x, int y, int color)
{
	t_data  img;

	img.img = mlx_new_image(mlx, 1000, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	my_mlx_pixel_put(&img, x, y, color);
	mlx_put_image_to_window(mlx, window, img.img, 0, 0);
}

void	draw_square(void *mlx, void *window, unsigned int start_x, unsigned int start_y, int color, int size_x)
{
	unsigned int	max_y;
	unsigned int	max_x;

	max_y = start_y;
	max_x = start_x + (unsigned int)size_x;
	while (start_x <= max_x)
	{
		start_y = 0;
		while (start_y <= max_y)
		{
			put_pixel(mlx, window, start_x, start_y, color);
			start_y++;
		}
		start_x++;
	}
}

unsigned int	count_len_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return (0);
	while (matrice[i])
		i++;
	return (i);
}

int		get_color(char *value)
{
	if (atoi(value) == 0)
		return (0x00D8FF);
	if (atoi(value) == 1)
		return (0x50c836);
	return (0x00D8FF);
}

void	draw_line(void *mlx, void *window, char **line, int size_x, int size_y)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int 	i;
	(void)size_y;

	i = 0;
	x = 0;
	y = 40;
	while (line[i])
	{
		draw_square(mlx, window, x, y, get_color(line[i]), size_x);
		i++;
		x = x + size_x;
	}
}

int	main(void)
{
	void	*mlx;
	void	*window;
	int		size_win_x;
	int		size_win_y;
	int		size_x;
	int		size_y;
	

	size_win_x = 1000;
	size_win_y = 500;
	mlx = mlx_init();
	window = mlx_new_window(mlx, size_win_x, size_win_y, "Hello word");
	

	t_map	*map;
	map = NULL;
	char *line1[] = {"0", "1", "0", "0", "1", 0};
	char *line2[] = {"0", "0", "1", "0", "1", 0};

	map = lst_push_back(line1, map);
	map = lst_push_back(line2, map);
	// map[0] = line1;
	// char map[1] = line2;
	// char map[2] = 0;

	print_lst(map);
	exit(0);

	size_x = size_win_x / count_len_matrice(line1);
	size_y = size_win_y / count_len_matrice(line1);

	draw_line(mlx, window, line1, size_x, size_y);
	//put_img(mlx, window, "textures/img.xpm", 5, 5);
	//put_pixel_via_img(mlx, window, 0, 0, 0x00D8FF);
	//put_pixel(mlx, window, 5, 5, 0x00D8FF);
	mlx_loop(mlx);
	return (0);
}
