/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:08:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/29 18:26:45 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_terminate(char *error_message)
{
	ft_putstr(error_message);
	exit(EXIT_FAILURE);
}

// doesnt check for errors
int	parse_input(t_board *stack, char **av)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		addback(&stack->a, new_cell(ft_atoi(av[i])));
	}
	return (1);
}

void	check_input(int ac, char **av, t_board *stack)
{
	if (ac < 2)
		ft_terminate(ERROR);
	if (!parse_input(stack, av))
		ft_terminate(ERROR);
}
