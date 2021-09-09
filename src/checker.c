/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:23:09 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/09 17:37:53 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_action(t_board *stack, char *action)
{
	if (!ft_strcmp(action, "rb"))
		rb(stack, 0);
	else if (!ft_strcmp(action, "rr"))
		rr(stack, 0);
	else if (!ft_strcmp(action, "rra"))
		rra(stack, 0);
	else if (!ft_strcmp(action, "rrb"))
		rrb(stack, 0);
	else if (!ft_strcmp(action, "rrr"))
		rrr(stack, 0);
	 else if (!ft_strcmp(action, "sa"))
		sa(stack, 0);
	else if (!ft_strcmp(action, "sb"))
		sb(stack, 0);
	else if (!ft_strcmp(action, "ss"))
		ss(stack, 0);
	else if (!ft_strcmp(action, "pa") && !is_empty(stack->b))
		pa(stack, 0);
	else if (!ft_strcmp(action, "pb") && !is_empty(stack->a))
		pb(stack, 0);
	else if (!ft_strcmp(action, "ra"))
		ra(stack, 0);
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
		execute_action(stack, action);
		free(action);
	}
	if (is_sorted(stack->a) && !stack->b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stack);
	return (0);
}
