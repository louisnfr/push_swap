/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:38:20 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 00:16:48 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_on_top(t_stack *stack, int x)
{
	if (stack->value == x)
		return (1);
	return (0);
}

void	bring_on_top_a(t_board *stack, int x)
{
	if (!stack || is_on_top(stack->a, x))
		return ;
	if (where_is(x, stack->a) == 1)
		while (!is_on_top(stack->a, x))
			ra(stack, 1);
	else
		while (!is_on_top(stack->a, x))
			rra(stack, 1);
}

void	bring_a_push_b(t_board *stack, int x)
{
	bring_on_top_a(stack, x);
	pb(stack, 1);
}

void	split_to_b(t_board *stack)
{
	int avg;
	int size;

	avg = get_avg(stack->a);
	size = len(stack->a);
	while (size-- > 0)
	{
		if (stack->a->index < avg)
			pb(stack, 1);
		else
			ra(stack, 1);
	}
}

int	get_avg(t_stack *stack)
{
	float	total;
	int		size;
	int		i;

	if (len(stack) == 0)
		return (0);
	total = 0;
	size = len(stack);
	i = 0;
	while (stack)
	{
		total += (stack->index);
		stack = stack->next;
		i++;
	}
	return ((int)(total / (int)size + 0.5));
}
