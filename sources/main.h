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

typedef struct s_window {
	void			*mlx;
	void			*win;
	unsigned int	size_win_x;
	unsigned int	size_win_y;
	unsigned int	max_sq_x;
	unsigned int	max_sq_y;
	t_map			*map;
}				t_window;

typedef struct s_player {
	int	pos_x;
	int	pos_y;
}				t_player;

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
void			draw_line(t_window win, char **line, unsigned int line_nbr);
void			draw_square(t_window win, int start_x, int start_y, int color);
void			put_pixel(t_window win, int x, int y, int color);
unsigned int	count_len_lst(t_map *map);
t_map			*setup_map(void);
t_window		setup_window(t_map *map);
char			*ft_itoa(int nb);
void			draw_map(t_window window, t_map *map);
int				on_key_press(int keycode, t_window *window);
t_map			*move_top(t_map	*map, t_player player, t_window win);
t_player		get_player_position(t_map *map);
void			put_img(t_window win, char *path, int width, int height);
t_map			*move_bottom(t_map	*map, t_player player, t_window win);

#endif
