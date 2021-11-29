/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:42:28 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 00:42:35 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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
