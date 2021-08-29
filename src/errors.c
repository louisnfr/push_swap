/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:08:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/29 17:41:13 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_terminate(char *error_message)
{
	ft_putstr(error_message);
	exit(EXIT_FAILURE);
}

void	check_input(int ac, char **av)
{
	(void)av;
	
	if (ac < 2)
		ft_terminate(ERROR);
}
