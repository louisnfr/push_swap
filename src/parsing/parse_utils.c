/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:41:07 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 00:25:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	empty_string(char *av)
{
	if (av[0] == 0)
		return (1);
	return (0);
}

int	count_args(char **av)
{
	int	i;

	i = 0;
	while (av && av[i])
		i++;
	return (i);
}
