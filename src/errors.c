/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:08:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/08/31 17:14:27 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_terminate(char *error_message, t_board *stack)
{
	free(stack);
	ft_putstr(error_message);
	exit(EXIT_FAILURE);
}

void	check_arg(char *string, t_board *stack)
{
	int i;

	i = -1;
	while (string[++i])
		if (!ft_isdigit(string[i]))
			ft_terminate(ERROR, stack);
}

// doesnt check for errors
int	parse_input(t_board *stack, char **av)
{
	int		i;

	i = 0;
	while (av[++i])
	{
		check_arg(av[i], stack);
		addback(&stack->a, new_cell(ft_atoi(av[i])));
	}
	return (1);
}

void	check_input(int ac, char **av, t_board *stack)
{
	if (ac < 2)
		ft_terminate(ERROR, stack);
	if (!parse_input(stack, av))
		ft_terminate(ERROR, stack);
}
