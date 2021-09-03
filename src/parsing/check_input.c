/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 20:08:50 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/03 18:13:30 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	check_arg(t_board *stack, char *av)
{
	int	i;

	if (ft_strcmp(av, "-") == 0 || ft_strcmp(av, "+") == 0)
		terminate(ERROR, stack);
	if (av[0] == '-' || av[0] == '+')
		i = 0;
	else
		i = -1;
	while (av[++i])
		if (!ft_isdigit(av[i]))
			terminate(ERROR, stack);
}

void	parse_input(t_board *stack, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (av[++i])
	{
		count = 0;
		j = 0;
		check_arg(stack, av[i]);
		while (av[++j])
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				count++;
		if (count != 1 || ft_atol(av[i]) > 2147483647
			|| ft_atol(av[i]) < -2147483648)
			terminate(ERROR, stack);
		addback(&stack->a, new_cell(ft_atoi(av[i])));
		stack->length++;
	}
}

void	check_input(int ac, char **av, t_board *stack)
{
	if (ac < 2)
		terminate(ERROR, stack);
	parse_input(stack, av);
}
