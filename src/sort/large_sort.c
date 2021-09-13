/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:34:53 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 04:19:41 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	backtrack_split(t_board *stack, int max)
{
	int	avg;
	int	c;
	int	i;

	c = 0;
	avg = get_avg_limit(stack->a, max);
	while (stack->a->index <= max && stack->a->index != 1)
	{
		if (stack->a->index >= avg)
		{
			ra(stack, 1);
			c++;
		}
		else
			pb(stack, 1);
	}
	i = -1;
	while (++i < c)
		if (stack->b->index != largest_index(stack->b))
			rrr(stack, 1);
	else
		rra(stack, 1);
	if (smallest_index(stack->b) == getlast(stack->a)->index + 1 && c > 0)
		push_swap(stack);
}

void	backtrack(t_board *stack, int max)
{
	while (stack->a->index <= max && stack->a->index != 1)
	{
		if (getlast(stack->a)->index + 1 == stack->a->index)
			ra(stack, 1);
		else
			pb(stack, 1);
	}
	if (smallest_index(stack->b) == getlast(stack->a)->index + 1)
		push_swap(stack);
}

void	push_swap(t_board *stack)
{
	int	max;

	if (len(stack->b) == 0)
		return ;
	max = largest_index(stack->b);
	split_to_a(stack, get_avg(stack->b), len(stack->b));
	while ((stack->a->index
			== getlast(stack->a)->index + 1
			|| stack->a->index == 1) && !is_sorted(stack->a))
		ra(stack, 1);
	push_swap(stack);
	if (get_size(stack->a, max) >= 20)
		backtrack_split(stack, max);
	backtrack(stack, max);
}

void	large_sort(t_board *stack)
{
	if (is_sorted(stack->a))
		return ;
	split_to_b(stack);
	push_swap(stack);
	if (get_size(stack->a, largest_index(stack->a)) >= 20)
	{
		backtrack_split(stack, largest_index(stack->a));
		backtrack_split(stack, largest_index(stack->a));
	}
	backtrack(stack, largest_index(stack->a));
}
