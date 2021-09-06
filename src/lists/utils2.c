/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:38:20 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/06 22:30:13 by lraffin          ###   ########.fr       */
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
			ra(stack);
	else
		while (!is_on_top(stack->a, x))
			rra(stack);
}

void	bring_on_top_b(t_board *stack, int x)
{
	if (!stack || is_on_top(stack->b, x))
		return ;
	if (where_is(x, stack->b) == 1)
		while (!is_on_top(stack->b, x))
			rb(stack);
	else
		while (!is_on_top(stack->b, x))
			rrb(stack);
}

void	bring_b_push_a(t_board *stack, int x)
{
	bring_on_top_b(stack, x);
	pa(stack);
}

void	bring_a_push_b(t_board *stack, int x)
{
	bring_on_top_a(stack, x);
	pb(stack);
}
