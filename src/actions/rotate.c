/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:48:00 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/07 02:07:42 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rotate(t_stack	*stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!stack || !stack->next)
		return (stack);
	last = getlast(stack);
	tmp = stack;
	stack = stack->next;
	tmp->next = NULL;
	last->next = tmp;
	return (stack);
}

void	ra(t_board *stack, int print)
{
	stack->a = rotate(stack->a);
	if (print)
		write(1, "ra\n", 3);
	stack->moves++;
}

void	rb(t_board *stack, int print)
{
	stack->b = rotate(stack->b);
	if (print)
		write(1, "rb\n", 3);
	stack->moves++;
}

void	rr(t_board *stack, int print)
{
	stack->a = rotate(stack->a);
	stack->b = rotate(stack->b);
	if (print)
		write(1, "rr\n", 3);
	stack->moves++;
}
