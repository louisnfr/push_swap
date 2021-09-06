/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:20:55 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 19:40:06 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pb_q2(t_board *stack, t_quart *quart)
{
	while (smallest(stack->a) <= quart->q2)
	{
		if (stack->a->value <= quart->q2)
			pb(stack);
		else
			ra(stack);
	}
}

void	half_on_a(t_board *stack, t_quart *quart)
{
	while (largest(stack->b) >= quart->q2)
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value >= quart->q2)
			pa(stack);
		else
			rb(stack);
	}
}

void	sort_rest_a(t_board *stack)
{
	while (stack->b && !is_empty(stack->b))
	{
		if (stack->b->value == smallest(stack->b))
		{
			pa(stack);
			ra(stack);
		}
		else if (stack->b->value == largest(stack->b))
			pa(stack);
		else
			rb(stack);
	}
}

void	ra_sorted_half_on_b(t_board *stack, t_quart *quart, int max)
{
	while (stack->a->value <= quart->q2)
		ra(stack);
	while (stack->a->value >= quart->q2 && stack->a->value <= max)
		pb(stack);
}
