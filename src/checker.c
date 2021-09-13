/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 22:23:09 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 17:00:14 by lraffin          ###   ########.fr       */
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

void	read_actions(t_board *stack)
{
	char	action[4];
	int		index;
	int		prev_index;

	index = 0;
	while (index < 4)
	{
		prev_index = index;
		index += read(0, action + index, 1);
		if (prev_index == index)
			break ;
		if (action[prev_index] == '\n')
		{
			action[prev_index] = 0;
			if (!execute_action(stack, action))
				terminate(ERROR, stack);
			index = 0;
		}
	}
	if (index == 4)
		terminate(ERROR, stack);
}

int	main(int ac, char **av)
{
	t_board	*stack;

	stack = init_board();
	check_input(ac, av, stack);
	read_actions(stack);
	if (is_sorted(stack->a) && is_empty(stack->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_all(stack);
	return (0);
}
