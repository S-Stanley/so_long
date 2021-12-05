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

t_img	*image_push_back(t_img *new_image, t_img *img)
{
	t_img	*tmp;

	if (!new_image)
		return (img);
	if (!img)
		return (new_image);
	tmp = img;
	while (img->next)
		img = img->next;
	img->next = new_image;
	return (tmp);
}

void	free_images(t_img *img, t_window win)
{
	t_img	*tmp;

	if (!img)
		return ;
	tmp = img;
	(void)win;
	while (img)
	{
		tmp = img->next;
		mlx_destroy_image(win.mlx, img->img);
		free(img);
		img = tmp;
	}
}

void	put_str(char *str)
{
	write(1, str, ft_strlen(str));
}

t_img	*put_img(t_window win, char *path, int width, int height)
{
	t_img	*image;

	image = malloc(sizeof(t_img));
	if (!image)
		return (win.img);
	image->img = mlx_xpm_file_to_image(
			win.mlx, path, &image->width, &image->height);
	if (!image->img)
	{
		put_str("Failed to get xpm image\n");
		print_matrice(win.map->line);
		free(image);
		free_images(win.img, win);
		free_lst(win.map);
		mlx_destroy_window(win.mlx, win.win);
		mlx_destroy_display(win.mlx);
		free(win.mlx);
		exit(1);
	}
	image->next = NULL;
	mlx_put_image_to_window(win.mlx, win.win, image->img, width, height);
	win.img = image_push_back(image, win.img);
	return (win.img);
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
