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
# include <fcntl.h>
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
	void	*next;
}		t_img;

typedef struct s_window {
	void			*mlx;
	void			*win;
	unsigned int	size_win_x;
	unsigned int	size_win_y;
	unsigned int	max_sq_x;
	unsigned int	max_sq_y;
	unsigned int	nb_move;
	t_map			*map;
	t_img			*img;
	t_map			*map_start;
	t_img			*img_start;
}				t_window;

typedef struct s_player {
	int	pos_x;
	int	pos_y;
}				t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		ll;
	int		endian;
}		t_data;

typedef struct s_parsing {
	t_map			*map;
	char			**arr;
	unsigned int	i;
}	t_parsing;

unsigned int	ft_strlen(const char *str);
t_map			*lst_push_back(char **line, t_map *map);
t_map			*new_lst(char **line);
void			print_lst(t_map *map);
unsigned int	count_len_matrice(char **matrice);
char			*ft_strdup(const char *str);
char			**copy_matrice(char **matrice);
void			print_matrice(char **matrice);
int				get_color(char *value);
t_img			*draw_line(t_window win, char **line, unsigned int line_nbr);
void			draw_square(t_window win, int start_x, int start_y, int color);
void			put_pixel(t_window win, int x, int y, int color);
unsigned int	count_len_lst(t_map *map);
t_window		setup_window(t_map *map);
char			*ft_itoa(int nb);
t_img			*draw_map(t_window window);
int				on_key_press(int keycode, t_window *window);
t_window		move_top(t_map	*map, t_player player, t_window win);
t_player		get_player_position(t_map *map);
t_img			*put_img(t_window *window, char *path, int width, int height);
t_window		move_bottom(t_map	*map, t_player player, t_window win);
void			free_lst(t_map *map);
void			free_that_matrice(char **matrice);
t_window		move_left(t_map *map, t_player player, t_window win);
t_window		move_right(t_map *map, t_player player, t_window win);
void			exit_game(t_window window);
void			free_images(t_img *img, t_window win);
char			**push_arr(char **arr, char *to_add);
t_map			*setup_map(const char *file);
unsigned int	can_he_move_here(char pos, t_window win);
unsigned int	print_move(unsigned int nb_move);
void			should_exit(char pos, t_window win);
void			check_map(t_map *map);
void			print_and_exit(char *message);
int				on_buton_press(t_window *window);
char			*get_image_path(char code);
char			*create_str_from_char(char c);
void			put_str(char *str);
void			print_and_exit_game(char *str, t_window win);

#endif
