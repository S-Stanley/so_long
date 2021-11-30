/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <stanleyserbin@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 00:51:39 by sserbin           #+#    #+#             */
/*   Updated: 2021/11/30 00:51:40 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	get_color(char *value)
{
	if (atoi(value) == 0)
		return (0x00D8FF);
	if (atoi(value) == 1)
		return (0x50c836);
	return (0x00D8FF);
}
