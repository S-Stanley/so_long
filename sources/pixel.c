/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 01:29:29 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 01:29:30 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	put_img(t_window win, char *path, int width, int height)
{
	void	*img;
	char	*str;

	img = mlx_xpm_file_to_image(win.mlx, path, &width, &height);
	if (!img)
	{
		str = "Failed to get xpm image\n";
		write(1, str, ft_strlen(str));
		exit(0);
	}
	mlx_put_image_to_window(win.mlx, win.win, img, 0, 0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->ll + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	put_pixel(t_window win, int x, int y, int color)
{
	mlx_pixel_put(win.mlx, win.win, x, y, color);
}

void	put_pixel_via_img(t_window win, int x, int y, int color)
{
	t_data	img;

	img.img = mlx_new_image(win.mlx, 1000, 500);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.ll, &img.endian);
	my_mlx_pixel_put(&img, x, y, color);
	mlx_put_image_to_window(win.mlx, win.win, img.img, 0, 0);
}
