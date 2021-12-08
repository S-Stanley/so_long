/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sserbin <sserbin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 01:13:10 by sserbin           #+#    #+#             */
/*   Updated: 2021/12/08 01:14:11 by sserbin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_parsing	arr_not_empty(t_parsing parsing)
{
	parsing.map = lst_push_back(parsing.arr, parsing. map);
	free_that_matrice(parsing.arr);
	return (parsing);
}

void	free_and_exit_error_buff(char *buffer, t_parsing parsing)
{
	free(buffer);
	free_lst(parsing.map);
	print_and_exit("Error while allocating buffer\n");
}
