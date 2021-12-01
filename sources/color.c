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
	if (value[0] == 'P')
		return (0xffffff);
	if (value[0] == 'C')
		return (0xcccccc);
	if (value[0] == 'E')
		return (0x2f1b0c);
	if (value[0] == '0')
		return (0x50c836);
	if (value[0] == '1')
		return (0x00D8FF);
	return (0x00D8FF);
}
