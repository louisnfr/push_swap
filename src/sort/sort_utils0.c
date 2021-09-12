/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:20:55 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 00:21:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_max_to_a(t_board *stack)
{
	if (stack->b->index == largest_index(stack->b))
		pa(stack, 1);
	else
	{
		if (getlast(stack->a)->index + 1 == stack->b->index || stack->b->index == 1)
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else
			smart_rotate(stack);
	}
}

void	smart_rotate(t_board *stack)
{

	if (where_is_index(largest_index(stack->b), stack->b) == 1)
		rb(stack, 1);
	else
		rrb(stack, 1);
}

void	split_to_a(t_board *stack, int avg, int size)
{
	while (size-- > 0)
	{
		if (len(stack->b) < 13)
			get_max_to_a(stack);
		else
		{
			if (stack->b->index >= avg)
				pa(stack, 1);
			else
			{
				if (getlast(stack->a)->index + 1 == stack->b->index || stack->b->index == 1)
				{
					pa(stack, 1);
					ra(stack, 1);
				}
				else
					rb(stack, 1);
			}
		}
	}
}

int	get_size(t_stack *stack, int max)
{
	int	i;

	if (len(stack) == 0)
		return (0);
	i = 0;
	while (stack->index <= max && stack->index != 1)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	get_avg_limit(t_stack *stack, int max)
{
	float	total;
	int		i;

	if (len(stack) == 0)
		return (0);
	total = 0;
	i = 0;
	while (stack->index <= max
		&& stack->index != 1)
	{
		total += stack->index;
		stack = stack->next;
		i++;
	}
	return ((int)(total / i + 0.5));
}
