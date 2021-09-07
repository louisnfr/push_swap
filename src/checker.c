/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:23:09 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 22:45:31 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_read_action(t_board *stack, char *action)
{
	if (!ft_strcmp(action, "rb"))
		rb(stack);
	else if (!ft_strcmp(action, "rr"))
		rr(stack);
	else if (!ft_strcmp(action, "rra"))
		rra(stack);
	else if (!ft_strcmp(action, "rrb"))
		rrb(stack);
	else if (!ft_strcmp(action, "rrr"))
		rrr(stack);
	 else if (!ft_strcmp(action, "sa"))
		sa(stack);
	else if (!ft_strcmp(action, "sb"))
		sb(stack);
	else if (!ft_strcmp(action, "ss"))
		ss(stack);
	else if (!ft_strcmp(action, "pa") && !is_empty(stack->b))
		pa(stack);
	else if (!ft_strcmp(action, "pb") && !is_empty(stack->a))
		pb(stack);
	else if (!ft_strcmp(action, "ra"))
		ra(stack);
	else
		terminate(ERROR, stack);
	return (1);
}

int	main(int ac, char **av)
{
	t_board	*stack;
	char	*action;

	stack = init_board();
	check_input(ac, av, stack);
	while (get_next_line(0, &action))
	{
		execute_read_action(stack, action);
		free(action);
	}
	if (is_sorted(stack->a) && is_empty(stack->b))
	{
		write(1, "OK\n", 3);
		free_all(stack);
	}
	else
	{
		write(1, "KO\n", 3);
		terminate(ERROR, stack);
	}
	terminate(ERROR, stack);
	return (0);
}