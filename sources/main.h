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
# include "../minilibx-linux/mlx.h"

typedef struct s_img {
	void	*img;
	char	*path;
	int	width;
	int	height;
}		t_img;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int	bpp;
	int	ll;
	int	endian;
}		t_data;

#endif
