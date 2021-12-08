/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <sserbin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:42:50 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/08 01:11:49 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

unsigned int	ft_strlen(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	put_str(char *str)
{
	write(1, str, ft_strlen(str));
}

char	*create_str_from_char(char c)
{
	char	*to_return;

	to_return = malloc(sizeof(char *) * 2);
	if (!to_return)
		return (NULL);
	to_return[0] = c;
	to_return[1] = 0;
	return (to_return);
}

char	*ft_strdup(const char *str)
{
	char			*to_return;
	unsigned int	i;

	to_return = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!to_return)
		return (NULL);
	i = 0;
	while (str[i])
	{
		to_return[i] = str[i];
		i++;
	}
	to_return[i] = 0;
	return (to_return);
}

unsigned int	is_white_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}
