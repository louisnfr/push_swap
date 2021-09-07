/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:20:55 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 15:02:06 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_4_5(t_board *stack)
{
	bring_a_push_b(stack, smallest(stack->a));
	if (len(stack->a) > 3)
		bring_a_push_b(stack, largest(stack->a));
}

void	pa_q2(t_board *stack, t_quart *quart)
{
	while (largest(stack->b) >= quart->q2)
	{
		if (stack->b->value >= quart->q2)
			pa(stack, 1);
		else if (stack->b->value == smallest(stack->b))
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else if (closest_above_k(stack->b, quart->q2) == 1)
			rb(stack, 1);
		else
			rrb(stack, 1);
	}
}

void	pb_q2(t_board *stack, t_quart *quart)
{
	while (smallest(stack->a) <= quart->q2)
	{
		if (stack->a->value <= quart->q2)
			pb(stack, 1);
		else if (getlast(stack->a)->value == smallest(stack->a)
				&& last_below_k(stack->a, quart->q2))
			return ;
		else if (closest_below_k(stack->a, quart->q2) == 1)
			ra(stack, 1);
		else
			rra(stack, 1);
	}
}

void	half_on_a(t_board *stack, t_quart *quart)
{
	while (largest(stack->b) >= quart->q2)
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else if (stack->b->value >= quart->q2)
			pa(stack, 1);
		else
			rb(stack, 1);
	}
}

void	sort_rest_a(t_board *stack)
{
	while (stack->b && !is_empty(stack->b))
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack, 1);
			ra(stack, 1);
		}
		else if (stack->b->value == largest(stack->b))
			pa(stack, 1);
		else
			rb(stack, 1);
	}
}

void	ra_sorted_half_on_b(t_board *stack, int quart, int max)
{
	while (stack->a->value <= quart)
		ra(stack, 1);
	while (stack->a->value >= quart && stack->a->value <= max)
		pb(stack, 1);
}
