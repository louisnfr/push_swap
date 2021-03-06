/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lraffin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 13:47:37 by lraffin           #+#    #+#             */
/*   Updated: 2021/09/13 16:19:23 by lraffin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*reverse_rotate(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*prev;

	if (!stack || !stack->next)
		return (stack);
	tmp = stack;
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	tmp->next = stack;
	stack = tmp;
	prev->next = NULL;
	return (stack);
}

void	rra(t_board *stack, int print)
{
	stack->a = reverse_rotate(stack->a);
	if (print)
		write(1, "rra\n", 4);
	stack->moves++;
}

void	rrb(t_board *stack, int print)
{
	stack->b = reverse_rotate(stack->b);
	if (print)
		write(1, "rrb\n", 4);
	stack->moves++;
}

void	rrr(t_board *stack, int print)
{
	stack->a = reverse_rotate(stack->a);
	stack->b = reverse_rotate(stack->b);
	if (print)
		write(1, "rrr\n", 4);
	stack->moves++;
}
