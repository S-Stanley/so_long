/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 19:01:36 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/21 19:01:37 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "string.h"

typedef struct s_map {
	char	**line;
	void	*next;
}				t_map;

typedef struct s_img {
	void	*img;
	char	*path;
	int		width;
	int		height;
}		t_img;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}		t_data;

unsigned int	ft_strlen(const char *str);
t_map			*lst_push_back(char **line, t_map *map);
t_map			*new_lst(char **line);
void			print_lst(t_map *map);
unsigned int	count_len_matrice(char **matrice);
char			*ft_strdup(const char *str);
char			**copy_matrice(char **matrice);
void			print_matrice(char **matrice);
int				get_color(char *value);
void			draw_line(void *mlx, void *window, char **line, int size_x, int size_y, unsigned int line_nbr);
void			draw_square(void *mlx, void *window, unsigned int start_x, unsigned int start_y, int color, int size_x);
void			put_pixel(void *mlx, void *window, int x, int y, int color);

#endif
