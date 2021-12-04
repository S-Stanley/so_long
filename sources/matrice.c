/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:43:07 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 00:43:08 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

char	**copy_matrice(char **matrice)
{
	char			**to_return;
	unsigned int	i;

	i = 0;
	to_return = malloc(sizeof(char *) * (count_len_matrice(matrice) + 1));
	while (matrice[i])
	{
		to_return[i] = ft_strdup(matrice[i]);
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}

void	print_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	while (matrice[i])
	{
		write(1, matrice[i], ft_strlen(matrice[i]));
		if (matrice[i + 1])
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}


char    **push_arr(char **arr, char *to_add)
{
    unsigned int	i;
	char			**to_return;

	to_return = malloc(sizeof(char *) * (count_len_matrice(arr) + 2));
	i = 0;
	if (arr)
	{
		while (arr[i])
		{
			to_return[i] = arr[i];
			i++;
		}
	}
	to_return[i] = to_add;
	to_return[++i] = 0;
	free(arr);
	return (to_return);
}

void	free_that_matrice(char **matrice)
{
	unsigned int	i;

	i = 0;
	if (!matrice)
		return ;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
}
